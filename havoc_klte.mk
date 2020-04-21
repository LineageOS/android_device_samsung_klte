# Inherit some common HAVOC stuff.
$(call inherit-product, vendor/havoc/config/common_full_phone.mk)

$(call inherit-product, device/samsung/klte/full_klte.mk)

PRODUCT_DEVICE := klte
PRODUCT_NAME := havoc_klte
