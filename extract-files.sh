#!/bin/sh

set -e

export VENDOR=samsung
export DEVICE=klte
./../../$VENDOR/klte-common/extract-files.sh $@
