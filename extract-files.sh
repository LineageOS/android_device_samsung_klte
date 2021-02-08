#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2020-2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

set -e

export DEVICE=klte
export DEVICE_COMMON=klte-common
export VENDOR=samsung

function blob_fixup() {
    case "${1}" in
        vendor/lib/libsec-ril.*)
            "${PATCHELF}" --replace-needed libcutils.so libcutils-v29.so \
                --replace-needed libprotobuf-cpp-full.so libprotobuf-cpp-full-v23.so \
                --replace-needed libprotobuf-cpp-haxx.so libprotobuf-cpp-full-v23.so \
                "${2}"
            ;;
    esac
}

# Load extract_utils and do some sanity checks
MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "${MY_DIR}" ]]; then MY_DIR="${PWD}"; fi

ANDROID_ROOT="${MY_DIR}/../../.."

HELPER="${ANDROID_ROOT}/tools/extract-utils/extract_utils.sh"
if [ ! -f "${HELPER}" ]; then
    echo "Unable to find helper script at ${HELPER}"
    exit 1
fi
source "${HELPER}"

if [ $# -eq 0 ]; then
    SRC=adb
else
    if [ $# -eq 1 ]; then
        SRC=$1
    else
        echo "$0: bad number of arguments"
        echo ""
        echo "usage: $0 [PATH_TO_EXPANDED_ROM]"
        echo ""
        echo "If PATH_TO_EXPANDED_ROM is not specified, blobs will be extracted from"
        echo "the device using adb pull."
        exit 1
    fi
fi
export SRC

setup_vendor "${DEVICE}" "${VENDOR}" "${ANDROID_ROOT}" false

for BLOB_LIST in "${MY_DIR}"/device-proprietary-files*.txt; do
    extract "${BLOB_LIST}" "${SRC}"
done

"./../../${VENDOR}/${DEVICE_COMMON}/extract-files.sh" "$@"

"${MY_DIR}/setup-makefiles.sh"
