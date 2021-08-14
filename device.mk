#
# Copyright (C) 2014 The CyanogenMod Project
# Copyright (C) 2017-2021 The LineageOS Project
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

$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Get non-open-source specific aspects
$(call inherit-product, vendor/samsung/klte/klte-vendor.mk)
$(call inherit-product, vendor/samsung/klte-common/klte-common-vendor-ril-m.mk)

# Overlays
DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

# Fingerprint
$(call inherit-product, device/samsung/klte-common/fingerprint/product.mk)

# NFC
$(call inherit-product, device/samsung/klte-common/nfc/pn547/product.mk)

# common klte
$(call inherit-product, device/samsung/klte-common/klte.mk)
