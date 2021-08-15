# Inherit some common Evolution-X stuff.
$(call inherit-product, vendor/evolution/config/common_full_phone.mk)

$(call inherit-product, device/samsung/klte/full_klte.mk)

PRODUCT_DEVICE := klte
PRODUCT_NAME := evolution_klte
TARGET_BOOT_ANIMATION_RES := 1080

CUSTOM_BUILD_TYPE := UNOFFICIAL
TARGET_GAPPS_ARCH := arm

# Maintainer Properties
EVO_DONATE_URL := https://t.me/cnkzlyr
EVO_SUPPORT_URL := https://t.me/TeamExyKings_S5
EVO_MAINTAINER := cnkzlyr (Can KIZILYAR)