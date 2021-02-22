# Inherit some common Evolution-X stuff.
$(call inherit-product, vendor/evolution/config/common_full_phone.mk)

$(call inherit-product, device/samsung/klte/full_klte.mk)

PRODUCT_DEVICE := klte
PRODUCT_NAME := evolution_klte
TARGET_BOOT_ANIMATION_RES := 1080

CUSTOM_BUILD_TYPE := UNOFFICIAL
TARGET_GAPPS_ARCH := arm
