#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2020 The LineageOS Project
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

set -e

export DEVICE=klte
export DEVICE_COMMON=klte-common
export VENDOR=samsung

./../$DEVICE_COMMON/extract-files.sh $@

MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "$MY_DIR" ]]; then MY_DIR="$PWD"; fi

CM_ROOT="$MY_DIR"/../../..
DEVICE_BLOB_ROOT="$CM_ROOT"/vendor/"$VENDOR"/"$DEVICE"/proprietary

for f in "$DEVICE_BLOB_ROOT"/vendor/lib/libsec-ril.*; do
  patchelf --replace-needed libcutils.so libcutils-v29.so \
    --replace-needed libprotobuf-cpp-full.so libprotobuf-cpp-full-v23.so \
    --replace-needed libprotobuf-cpp-haxx.so libprotobuf-cpp-full-v23.so \
    "$f"
done
