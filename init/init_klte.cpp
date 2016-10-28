/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.

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

void init_target_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = property_get("ro.bootloader");

    if (bootloader.find("G900W8") == 0) {
        /* kltecan */
        property_set("ro.build.fingerprint", "samsung/kltevl/kltecan:6.0.1/MMB29M/G900W8VLU1DPD3:user/release-keys");
        property_set("ro.build.description", "kltevl-user 6.0.1 MMB29M G900W8VLU1DPD3 release-keys");
        property_set("ro.product.model", "SM-G900W8");
        property_set("ro.product.device", "kltecan");
    } else if (bootloader.find("G900T") == 0) {
        /* kltetmo */
        property_set("ro.build.fingerprint", "samsung/kltetmo/kltetmo:6.0.1/MMB29M/G900TUVU1GPE1:user/release-keys");
        property_set("ro.build.description", "kltetmo-user 6.0.1 MMB29M G900TUVU1GPE1 release-keys");
        property_set("ro.product.model", "SM-G900T");
        property_set("ro.product.device", "kltetmo");
    } else if (bootloader.find("G900M") == 0) {
        /* klteub */
        property_set("ro.build.fingerprint", "samsung/klteub/klte:6.0.1/MMB29M/G900MUBU1CPC4:user/release-keys");
        property_set("ro.build.description", "klteub-user 6.0.1 MMB29M G900MUBU1CPC4 release-keys");
        property_set("ro.product.model", "SM-G900M");
        property_set("ro.product.device", "klte");
    } else if (bootloader.find("G900A") == 0) {
        /* klteatt */
        property_set("ro.build.fingerprint", "samsung/klteuc/klteatt:5.1.1/LMY47X/G900AUCU4CPA1:user/release-keys");
        property_set("ro.build.description", "klteuc-user 5.1.1 LMY47X G900AUCU4CPA1 release-keys");
        property_set("ro.product.model", "SM-G900A");
        property_set("ro.product.device", "klteatt");
    } else if (bootloader.find("G900S") == 0) {
        /* klteskt */
        property_set("ro.build.fingerprint", "samsung/klteskt/klteskt:6.0.1/MMB29M/G900SKSU1CPB9:user/release-keys");
        property_set("ro.build.description", "klteskt-user 6.0.1 MMB29M G900SKSU1CPB9 release-keys");
        property_set("ro.product.model", "SM-G900S");
        property_set("ro.product.device", "klteskt");
    } else if (bootloader.find("G900K") == 0) {
        /* kltektt */
        property_set("ro.build.fingerprint", "samsung/kltektt/kltektt:6.0.1/MMB29M/G900KKTU1CPE1:user/release-keys");
        property_set("ro.build.description", "kltektt-user 6.0.1 MMB29M G900KKTU1CPE1 release-keys");
        property_set("ro.product.model", "SM-G900K");
        property_set("ro.product.device", "kltektt");
    } else {
        /* kltexx */
        property_set("ro.build.fingerprint", "samsung/kltexx/klte:6.0.1/MMB29M/G900FXXS1CPHW:user/release-keys");
        property_set("ro.build.description", "kltexx-user 6.0.1 MMB29M G900FXXS1CPHW release-keys");
        property_set("ro.product.model", "SM-G900F");
        property_set("ro.product.device", "klte");
    }

    std::string device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}
