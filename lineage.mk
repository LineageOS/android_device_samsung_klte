$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

$(call inherit-product, device/samsung/klte/full_klte.mk)

PRODUCT_SKIP_FINGERPRINT_FROM_FILE := true 

PRODUCT_DEVICE := klte
PRODUCT_NAME := lineage_klte
