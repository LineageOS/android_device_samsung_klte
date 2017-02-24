/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm8974.h"

void cdma_properties(char const *operator_alpha,
        char const *operator_numeric,
        char const *default_network)
{
    /* Dynamic CDMA Properties */
    property_set("ro.cdma.home.operator.alpha", operator_alpha);
    property_set("ro.cdma.home.operator.numeric", operator_numeric);
    property_set("ro.telephony.default_network", default_network);

    /* Static CDMA Properties */
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("rild.libpath", "/system/lib/libsec-ril-vzw.so");
    property_set("ro.telephony.default_cdma_sub", "0");
    property_set("ro.telephony.get_imsi_from_sim", "true");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void gsm_properties()
{
    property_set("rild.libpath", "/system/lib/libsec-ril.so");
    property_set("ro.telephony.default_network", "9");
}

void init_target_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = property_get("ro.bootloader");

    if (bootloader.find("G900AZ") == 0) {
        /* klteaio - Cricket MVNO */
        property_set("ro.build.fingerprint", "samsung/kltetu/klteaio:5.0/LRX21T/G900AZTUS3BOGE:user/release-keys");
        property_set("ro.build.description", "kltetu-user 5.0 LRX21T G900AZTUS3BOGE release-keys");
        property_set("ro.product.model", "SM-G900AZ");
        property_set("ro.product.device", "klteaio");
        gsm_properties();
    } else if (bootloader.find("G900F") == 0) {
        /* kltexx */
        property_set("ro.build.fingerprint", "samsung/kltexx/klte:6.0.1/MMB29M/G900FXXS1CQAV:user/release-keys");
        property_set("ro.build.description", "kltexx-user 6.0.1 MMB29M G900FXXS1CQAV release-keys");
        property_set("ro.product.model", "SM-G900F");
        property_set("ro.product.device", "klte");
        gsm_properties();
    } else if (bootloader.find("G900M") == 0) {
        /* klteub */
        property_set("ro.build.fingerprint", "samsung/klteub/klte:6.0.1/MMB29M/G900MUBS1CPL8:user/release-keys");
        property_set("ro.build.description", "klteub-user 6.0.1 MMB29M G900MUBS1CPL8 release-keys");
        property_set("ro.product.model", "SM-G900M");
        property_set("ro.product.device", "klte");
        gsm_properties();
    } else if (bootloader.find("G900T") == 0) {
        /* kltetmo */
        property_set("ro.build.fingerprint", "samsung/kltetmo/kltetmo:6.0.1/MMB29M/G900TUVS1GPK3:user/release-keys");
        property_set("ro.build.description", "kltetmo-user 6.0.1 MMB29M G900TUVS1GPK3 release-keys");
        property_set("ro.product.model", "SM-G900T");
        property_set("ro.product.device", "kltetmo");
        gsm_properties();
    } else if (bootloader.find("G900V") == 0) {
        /* kltevzw - SM-G900V - Verizon */
        property_set("ro.build.fingerprint", "Verizon/kltevzw/kltevzw:6.0.1/MMB29M/G900VVRS2DQA1:user/release-keys");
        property_set("ro.build.description", "kltevzw-user 6.0.1 MMB29M G900VVRS2DQA1 release-keys");
        property_set("ro.product.model", "SM-G900V");
        property_set("ro.product.device", "kltevzw");
        cdma_properties("Verizon", "311480", "10");
    } else if (bootloader.find("G900W8") == 0) {
        /* kltecan */
        property_set("ro.build.fingerprint", "samsung/kltevl/kltecan:6.0.1/MMB29M/G900W8VLS1DPF3:user/release-keys");
        property_set("ro.build.description", "kltevl-user 6.0.1 MMB29M G900W8VLS1DPF3 release-keys");
        property_set("ro.product.model", "SM-G900W8");
        property_set("ro.product.device", "kltecan");
        gsm_properties();
    } else if (bootloader.find("S902L") == 0) {
        /* kltetfnvzw - SM-S902L - TracFone Verizon MVNO */
        property_set("ro.build.fingerprint", "samsung/kltetfnvzw/kltetfnvzw:4.4.2/KOT49H/S902LUDUAOD3:user/release-keys");
        property_set("ro.build.description", "kltetfnvzw-user 4.4.2 KOT49H S902LUDUAOD3 release-keys");
        property_set("ro.product.model", "SM-S902L");
        property_set("ro.product.device", "kltetfnvzw");
        cdma_properties("TracFone", "310000", "10");
    } else {
        gsm_properties();
    }

    std::string device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}
