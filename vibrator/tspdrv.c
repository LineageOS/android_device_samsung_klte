/*
 * Copyright (C) 2011 CyanogenMod Project
 * Copyright (C) 2011 Daniel Hillenbrand
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

#define LOG_NDEBUG 0
#define LOG_TAG "tspdrv"
#include <log/log.h>

#include "tspdrv.h"

int vibrator_exists()
{
    int fd;

    fd = open(THE_DEVICE, O_RDWR);
    if(fd < 0) {
        ALOGE("%s is not available.", THE_DEVICE);
        return 0;
    }
    close(fd);

    fd = open(TSPDRV_DEVICE, O_RDWR);
    if(fd < 0) {
        ALOGE("%s is not available.", TSPDRV_DEVICE);
        return 0;
    }
    close(fd);

    return 1;
}

static int write_value(const char *devname, int timeout_ms)
{
    int nwr, fd, ret;
    char value[20];

    fd = open(devname, O_RDWR);
    if(fd < 0)
        return errno;

    nwr = sprintf(value, "%d\n", timeout_ms);
    ret = write(fd, value, nwr);

    close(fd);
    return (ret == nwr) ? 0 : -1;
}

static void tsp_set_timeout(int tspd, int timeout_ms, int actuators)
{
    int tspret;

    if(timeout_ms == 0) {
        /* stop tspdrv kernel timer */
        tspret = ioctl(tspd, TSPDRV_STOP_KERNEL_TIMER);
        if(tspret != 0) {
            ALOGE("TSPDRV_STOP_KERNEL_TIMER error: %d\n", tspret);
        }

        /* disable tspdrv amp */
        if(actuators >= 1) {
            tspret = ioctl(tspd, TSPDRV_DISABLE_AMP, actuators);
            if(tspret != 0) {
                ALOGE("TSPDRV_DISABLE_AMP error: %d\n", tspret);
            }
        }
    } else {
        if(timeout_ms > 0) {
            /* enable tspdrv amp */
            tspret = ioctl(tspd, TSPDRV_ENABLE_AMP, actuators);
            if(tspret != 0) {
                ALOGE("TSPDRV_ENABLE_AMP error: %d\n", tspret);
            }
        }
    }
}

int sendit(int timeout_ms)
{
    int tspd, tspret, actuators;

    tspd = open(TSPDRV_DEVICE, O_RDWR);
    if(tspd < 0) {
        ALOGE("failed on opening /dev/tspdrv\n");
	return errno;
    }

    /* send tspdrv magic number */
    tspret = ioctl(tspd, TSPDRV_MAGIC_NUMBER);
    if(tspret != 0) {
        ALOGE("TSPDRV_MAGIC_NUMBER error: %d\n", tspret);
    }

    /* get number of actuators */
    actuators = ioctl(tspd, TSPDRV_GET_NUM_ACTUATORS);
    if(actuators < 1) {
        ALOGE("TSPDRV_GET_NUM_ACTUATORS error, no actuators available\n");
	close(tspd);
	return -1;
    }

    tsp_set_timeout(tspd, timeout_ms, actuators);
    close(tspd);

    return write_value(THE_DEVICE, timeout_ms);
}
