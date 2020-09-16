/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

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

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "init_msm8974.h"

using android::base::GetProperty;

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("G900F") == 0) {
        /* kltexx */
        property_override("ro.build.description", "kltexx-user 6.0.1 MMB29M G900FXXU1CRH1 release-keys");
        set_ro_product_prop("device", "klte");
        set_ro_product_prop("fingerprint", "samsung/kltexx/klte:6.0.1/MMB29M/G900FXXU1CRH1:user/release-keys");
        set_ro_product_prop("model", "SM-G900F");
        set_ro_product_prop("name", "klte");
        gsm_properties("9", "gsm");
    } else if (bootloader.find("G900M") == 0) {
        /* klteub */
        property_override("ro.build.description", "klteub-user 6.0.1 MMB29M G900MUBS1CQD5 release-keys");
        set_ro_product_prop("device", "klte");
        set_ro_product_prop("fingerprint", "samsung/klteub/klte:6.0.1/MMB29M/G900MUBS1CQD5:user/release-keys");
        set_ro_product_prop("model", "SM-G900M");
        set_ro_product_prop("name", "klte");
        gsm_properties("9", "gsm");
    } else if (bootloader.find("G900R4") == 0) {
        /* klteusc */
        property_override("ro.build.description", "klteusc-user 6.0.1 MMB29M G900R4VXS2CQC2 release-keys");
        set_ro_product_prop("device", "klteusc");
        set_ro_product_prop("fingerprint", "samsung/klteusc/klteusc:6.0.1/MMB29M/G900R4VXS2CQC2:user/release-keys");
        set_ro_product_prop("model", "SM-G900R4");
        set_ro_product_prop("name", "klteusc");
        cdma_properties("U.S. Cellular", "311220", "0", "10", "usc");
    } else if (bootloader.find("G900R7") == 0) {
        /* klteacg - CSpire variant */
        property_override("ro.build.description", "klteacg-user 6.0.1 MMB29M G900R7WWU3CPL1 release-keys");
        set_ro_product_prop("device", "klteacg");
        set_ro_product_prop("fingerprint", "samsung/klteacg/klteacg:6.0.1/MMB29M/G900R7WWU3CPL1:user/release-keys");
        set_ro_product_prop("model", "SM-G900R7");
        set_ro_product_prop("name", "klteacg");
        cdma_properties("Default", "310000", "0", "10", "usc");
    } else if (bootloader.find("G900T") == 0) {
        /* kltetmo */
        property_override("ro.build.description", "kltetmo-user 6.0.1 MMB29M G900TUVU1GQC2 release-keys");
        property_override("persist.radio.add_power_save", "0");
        set_ro_product_prop("device", "kltetmo");
        set_ro_product_prop("fingerprint", "samsung/kltetmo/kltetmo:6.0.1/MMB29M/G900TUVU1GQC2:user/release-keys");
        set_ro_product_prop("model", "SM-G900T");
        set_ro_product_prop("name", "kltetmo");
        gsm_properties("9", "gsm");
    } else if (bootloader.find("G900V") == 0) {
        /* kltevzw - SM-G900V - Verizon */
        property_override("ro.build.description", "kltevzw-user 6.0.1 MMB29M G900VVRU2DQL1 release-keys");
        property_override("ro.telephony.get_imsi_from_sim", "true");
        set_ro_product_prop("device", "kltevzw");
        set_ro_product_prop("fingerprint", "Verizon/kltevzw/kltevzw:6.0.1/MMB29M/G900VVRU2DQL1:user/release-keys");
        set_ro_product_prop("model", "SM-G900V");
        set_ro_product_prop("name", "kltevzw");
        cdma_properties("Verizon", "311480", "0", "10", "vzw");
    } else if (bootloader.find("G900W8") == 0) {
        /* kltecan */
        property_override("ro.build.description", "kltevl-user 6.0.1 MMB29M G900W8VLU1DQB2 release-keys");
        property_override("persist.radio.add_power_save", "0");
        set_ro_product_prop("device", "kltecan");
        set_ro_product_prop("fingerprint", "samsung/kltevl/kltecan:6.0.1/MMB29M/G900W8VLU1DQB2:user/release-keys");
        set_ro_product_prop("model", "SM-G900W8");
        set_ro_product_prop("name", "kltecan");
        gsm_properties("9", "gsm");
    } else {
        gsm_properties("9", "gsm");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
