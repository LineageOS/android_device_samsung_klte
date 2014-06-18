/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

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

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void gsm_properties();
void cdma_properties(char cdma_sub[]);

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "G900W8")) {
        /* kltecan */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/kltevl/kltecan:4.3/JSS15J/N900W8VLUBMJ4:user/release-keys");
        property_set("ro.build.description", "kltevl-user 4.3 JSS15J N900W8VLUBMJ4 release-keys");
        property_set("ro.product.model", "SM-G900W8");
        property_set("ro.product.device", "kltecan");
    } else if (strstr(bootloader, "G900P")) {
        /* kltespr */
        cdma_properties("1");
        property_set("ro.build.fingerprint", "samsung/kltespr/kltespr:4.4.2/KOT49H/G900PVPU1ANCB:user/release-keys");
        property_set("ro.build.description", "kltespr-user 4.4.2 KOT49H G900PVPU1ANCB release-keys");
        property_set("ro.product.model", "SM-G900P");
        property_set("ro.product.device", "kltespr");
    } else if (strstr(bootloader, "G900R4")) {
        /* klteusc */
        cdma_properties("0");
        property_set("ro.build.fingerprint", "samsung/klteusc/klteusc:4.4.2/KOT49H/G900R4VXU1ANCF:user/release-keys");
        property_set("ro.build.description", "klteusc-user 4.4.2 KOT49H G900R4VXU1ANCF release-keys");
        property_set("ro.product.model", "SM-G900R4");
        property_set("ro.product.device", "klteusc");
    } else if (strstr(bootloader, "G900T")) {
        /* kltetmo */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/kltetmo/kltetmo:4.4.2/KOT49H/G900TUVU1ANCH:user/release-keys");
        property_set("ro.build.description", "kltetmo-user 4.4.2 KOT49H G900TUVU1ANCH release-keys");
        property_set("ro.product.model", "SM-G900T");
        property_set("ro.product.device", "kltetmo");
    } else if (strstr(bootloader, "G900I")) {
        /* kltedv */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/kltedv/klte:4.4.2/KOT49H/G900IDVU1ANC6:user/release-keys");
        property_set("ro.build.description", "kltedv-user 4.4.2 KOT49H G900IDVU1ANC6 release-keys");
        property_set("ro.product.model", "SM-G900I");
        property_set("ro.product.device", "kltedv");
    } else if (strstr(bootloader, "G900M")) {
        /* klteub */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/klteub/klte:4.4.2/KOT49H/G900MUBU1ANCE:user/release-keys");
        property_set("ro.build.description", "klteub-user 4.4.2 KOT49H G900MUBU1ANCE release-keys");
        property_set("ro.product.model", "SM-G900M");
        property_set("ro.product.device", "klteub");
    } else if (strstr(bootloader, "G900A")) {
        /* klteatt */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/klteatt/klte:4.4.2/KOT49H/G900AUCU2AND3:user/release-keys");
        property_set("ro.build.description", "klteatt-user 4.4.2 KOT49H G900AUCU2AND3 release-keys");
        property_set("ro.product.model", "SM-G900A");
        property_set("ro.product.device", "klteatt");
    } else if (strstr(bootloader, "G900R6")) {
        /* kltelra */
        cdma_properties("0");
        property_set("ro.build.fingerprint", "samsung/kltelra/kltelra:4.4.2/KOT49H/G900R6WWU2AND7:user/release-keys");
        property_set("ro.build.description", "kltelra-user 4.4.2 KOT49H G900R6WWU2AND7 release-keys");
        property_set("ro.product.model", "SM-G900R6");
        property_set("ro.product.device", "kltelra");
    } else if (strstr(bootloader, "G900R7")) {
        /* klteacg */
        cdma_properties("0");
        property_set("ro.build.fingerprint", "samsung/klteacg/klteacg:4.4.2/KOT49H/G900R7WWU2AND8:user/release-keys");
        property_set("ro.build.description", "klteacg-user 4.4.2 KOT49H G900R7WWU2AND8 release-keys");
        property_set("ro.product.model", "SM-G900R7");
        property_set("ro.product.device", "klteacg");
    } else if (strstr(bootloader, "G900V")) {
        /* hltevzw */
        cdma_properties("0");
        property_set("ro.build.fingerprint", "Verizon/kltevzw/kltevzw:4.4.2/KOT49H/G900VVRU1ANCG:user/release-keys");
        property_set("ro.build.description", "kltevzw-user 4.4.2 KOT49H G900VVRU1ANCG release-keys");
        property_set("ro.product.model", "SM-G900V");
        property_set("ro.product.device", "hltevzw");
        property_set("ro.telephony.default_cdma_sub", "0");
        property_set("ro.cdma.home.operator.alpha", "Verizon");
        property_set("ro.cdma.home.operator.numeric", "311480");
    } else if (strstr(bootloader, "G900F")) {
        /* kltexx */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/kltexx/klte:4.4.2/KOT49H/G900FXXU1ANCE:user/release-keys");
        property_set("ro.build.description", "kltexx-user 4.4.2 KOT49H G900FXXU1ANCE release-keys");
        property_set("ro.product.model", "SM-G900F");
        property_set("ro.product.device", "kltexx");
    }

    property_get("ro.product.device", device);
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, device);

}

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
    property_set("ro.telephony.ril.v3", "newDialCode");
}

void cdma_properties(char cdma_sub[])
{
    property_set("ro.telephony.ril.v3", "newDriverCallU,newDialCode");
    property_set("telephony.lteOnCdmaDevice", "1");
    property_set("ro.telephony.default_network", "10");
}
