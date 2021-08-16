# Inherit some common DOT-OS stuff.
$(call inherit-product, vendor/dot/config/common.mk)
$(call inherit-product, device/samsung/klte/full_klte.mk)

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := klte
PRODUCT_NAME := dot_klte
PRODUCT_BRAND := Samsung
PRODUCT_MANUFACTURER := Samsung
PRODUCT_RELEASE_NAME := klte
