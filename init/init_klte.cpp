/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2018, The LineageOS Project. All rights reserved.

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

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"
#include "vendor_init.h"

#include "init_msm8974.h"

using android::base::GetProperty;
using android::init::property_set;

void set_rild_libpath(char const *variant)
{
    std::string libpath("/system/vendor/lib/libsec-ril.");
    libpath += variant;
    libpath += ".so";

    property_override("rild.libpath", libpath.c_str());
}

void cdma_properties(char const *operator_alpha,
        char const *operator_numeric,
        char const *default_network,
        char const *rild_lib_variant)
{
    /* Dynamic CDMA Properties */
    property_set("ro.cdma.home.operator.alpha", operator_alpha);
    property_set("ro.cdma.home.operator.numeric", operator_numeric);
    property_set("ro.telephony.default_network", default_network);
    set_rild_libpath(rild_lib_variant);

    /* Static CDMA Properties */
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.telephony.default_cdma_sub", "0");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void gsm_properties(char const *rild_lib_variant)
{
    set_rild_libpath(rild_lib_variant);

    property_set("ro.telephony.default_network", "9");
    property_set("telephony.lteOnGsmDevice", "1");
}

void init_target_properties()
{
    std::string platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("G900AZ") == 0) {
        /* klteaio - Cricket MVNO */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/kltetu/klteaio:5.0/LRX21T/G900AZTUS3BQD1:user/release-keys");
        property_override("ro.build.description", "kltetu-user 5.0 LRX21T G900AZTUS3BQD1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-G900AZ");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "klteaio");
        gsm_properties("gsm");
    } else if (bootloader.find("G900F") == 0) {
        /* kltexx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/kltexx/klte:6.0.1/MMB29M/G900FXXU1CRA2:user/release-keys");
        property_override("ro.build.description", "kltexx-user 6.0.1 MMB29M G900FXXU1CRA2 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-G900F");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "klte");
        gsm_properties("gsm");
    } else if (bootloader.find("G900M") == 0) {
        /* klteub */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/klteub/klte:6.0.1/MMB29M/G900MUBS1CQD5:user/release-keys");
        property_override("ro.build.description", "klteub-user 6.0.1 MMB29M G900MUBS1CQD5 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-G900M");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "klte");
        gsm_properties("gsm");
    } else if (bootloader.find("G900R4") == 0) {
        /* klteusc */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/klteusc/klteusc:6.0.1/MMB29M/G900R4VXS2CQC2:user/release-keys");
        property_override("ro.build.description", "klteusc-user 6.0.1 MMB29M G900R4VXS2CQC2 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-G900R4");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "klteusc");
        cdma_properties("U.S. Cellular", "311220", "10", "usc");
    } else if (bootloader.find("G900R7") == 0) {
        /* klteacg - CSpire variant */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/klteacg/klteacg:6.0.1/MMB29M/G900R7WWU3CPL1:user/release-keys");
        property_override("ro.build.description", "klteacg-user 6.0.1 MMB29M G900R7WWU3CPL1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-G900R7");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "klteacg");
        cdma_properties("Default", "310000", "10", "usc");
    } else if (bootloader.find("G900T") == 0) {
        /* kltetmo */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/kltetmo/kltetmo:6.0.1/MMB29M/G900TUVU1GQC2:user/release-keys");
        property_override("ro.build.description", "kltetmo-user 6.0.1 MMB29M G900TUVU1GQC2 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-G900T");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "kltetmo");
        gsm_properties("gsm");
    } else if (bootloader.find("G900V") == 0) {
        /* kltevzw - SM-G900V - Verizon */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "Verizon/kltevzw/kltevzw:6.0.1/MMB29M/G900VVRU2DQL1:user/release-keys");
        property_override("ro.build.description", "kltevzw-user 6.0.1 MMB29M G900VVRU2DQL1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-G900V");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "kltevzw");
        property_set("ro.telephony.get_imsi_from_sim", "true");
        cdma_properties("Verizon", "311480", "10", "vzw");
    } else if (bootloader.find("G900W8") == 0) {
        /* kltecan */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/kltevl/kltecan:6.0.1/MMB29M/G900W8VLU1DQB2:user/release-keys");
        property_override("ro.build.description", "kltevl-user 6.0.1 MMB29M G900W8VLU1DQB2 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-G900W8");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "kltecan");
        gsm_properties("gsm");
    } else if (bootloader.find("S902L") == 0) {
        /* kltetfnvzw - SM-S902L - TracFone Verizon MVNO */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/kltetfnvzw/kltetfnvzw:4.4.2/KOT49H/S902LUDUAOD3:user/release-keys");
        property_override("ro.build.description", "kltetfnvzw-user 4.4.2 KOT49H S902LUDUAOD3 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-S902L");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "kltetfnvzw");
        property_set("ro.telephony.get_imsi_from_sim", "true");
        cdma_properties("TracFone", "310000", "10", "vzw");
    } else {
        gsm_properties("gsm");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
