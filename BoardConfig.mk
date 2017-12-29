# Copyright (C) 2014-2016 The CyanogenMod Project
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

# inherit from common klte
include device/samsung/klte-common/BoardConfigCommon.mk
include device/samsung/klte-common/fingerprint-board.mk

TARGET_OTA_ASSERT_DEVICE := klte,klteacg,klteatt,kltecan,kltelra,kltetmo,klteub,klteusc,kltevzw,kltexx

# Kernel
TARGET_KERNEL_CONFIG := lineage_klte_pn547_defconfig

# Init
TARGET_INIT_VENDOR_LIB := libinit_msm8974
TARGET_LIBINIT_MSM8974_DEFINES_FILE := device/samsung/klte/init/init_klte.cpp

# NFC
BOARD_NFC_CHIPSET := pn547
BOARD_NFC_HAL_SUFFIX := msm8974

# inherit from the proprietary version
-include vendor/samsung/klte/BoardConfigVendor.mk
