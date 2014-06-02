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

#ifndef __TSPDRV_H
#define __TSPDRV_H __FILE__

#define THE_DEVICE				"/sys/class/timed_output/vibrator/enable"
#define TSPDRV_DEVICE				"/dev/tspdrv"

#define TSPDRV_MAGIC_NUMBER			0x494D4D52
#define TSPDRV_STOP_KERNEL_TIMER 		_IO(TSPDRV_MAGIC_NUMBER & 0xFF, 1)
#define TSPDRV_ENABLE_AMP			_IO(TSPDRV_MAGIC_NUMBER & 0xFF, 3)
#define TSPDRV_DISABLE_AMP			_IO(TSPDRV_MAGIC_NUMBER & 0xFF, 4)
#define TSPDRV_GET_NUM_ACTUATORS 		_IO(TSPDRV_MAGIC_NUMBER & 0xFF, 5)

#endif /* __TSPDRV_H */
