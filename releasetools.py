# Copyright (C) 2012 The Android Open Source Project
# Copyright (C) 2014 The CyanogenMod Project
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

"""Custom OTA commands for klte devices"""

def FullOTA_InstallEnd(info):
  info.script.AppendExtra('ifelse(is_substring("G900A", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G900T", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G900D", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G9005", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G900F", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G900W", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G900I", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/etc/pn544/* /system/etc/"));')

  info.script.AppendExtra('ifelse(is_substring("G900M", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G900V", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G900R4", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G900R6", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('ifelse(is_substring("G900R7", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp /system/lib/hw/pn547/* /system/lib/hw/"));')

  info.script.AppendExtra('delete_recursive("/system/lib/hw/pn547/");')
  info.script.AppendExtra('delete_recursive("/system/etc/pn544/");')
