#
# Copyright (C) 2014 The CyanogenMod Project
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

$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Get non-open-source specific aspects
$(call inherit-product-if-exists, vendor/samsung/klte/klte-vendor.mk)

# Overlays
DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

# NFC
# See https://github.com/LineageOS/android_system_nfc/blob/lineage-15.0/halimpl/pn54x/Android.mk#L15
# for magic values of NXP_CHIP_TYPE.
NXP_CHIP_TYPE := 1
PRODUCT_PACKAGES += \
    libpn547_fw \
    nfc_nci.msm8974

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/libnfc-brcm.conf:system/vendor/etc/libnfc-brcm.conf \
    $(LOCAL_PATH)/configs/libnfc-nxp.conf:system/vendor/etc/libnfc-nxp.conf \
    $(LOCAL_PATH)/configs/nfcee_access.xml:system/vendor/etc/nfcee_access.xml

# common klte
$(call inherit-product, device/samsung/klte-common/klte.mk)
$(call inherit-product, device/samsung/klte-common/fingerprint-product.mk)
