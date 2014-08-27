#!/bin/sh

set -e

export VENDOR=samsung
export DEVICE=klte
./../../$VENDOR/klte-common/setup-makefiles.sh $@
