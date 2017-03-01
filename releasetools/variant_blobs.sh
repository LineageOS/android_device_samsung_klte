#!/sbin/sh
#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#


set -e

# Detect variant and copy its specific-blobs
BOOTLOADER=`getprop ro.bootloader`

case $BOOTLOADER in
    G900V*)      VARIANT="vzw" ;;
    *)           VARIANT="gsm" ;;
esac

BLOBBASE=/system/blobs/$VARIANT

if [ -d $BLOBBASE ]; then
    WHICH_BOX=`readlink \`which cp\``

    case $WHICH_BOX in
        busybox) PRESERVE="-c" ;;
        toybox)  PRESERVE="--preserve=c" ;;
        *)       PRESERVE="" ;;
    esac

    cd $BLOBBASE
    chmod 755 bin/*
    cp $PRESERVE -a * /system
else
    echo "Expected source directory does not exist!"
    exit 1
fi

exit 0
