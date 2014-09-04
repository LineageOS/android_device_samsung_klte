/*
 * Copyright (c) 2014, The CyanogenMod Project. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.internal.telephony;

import static com.android.internal.telephony.RILConstants.*;

import android.content.Context;
import android.telephony.Rlog;
import android.os.Message;
import android.os.Parcel;
import android.telephony.PhoneNumberUtils;
import android.telephony.SignalStrength;
import com.android.internal.telephony.uicc.IccCardApplicationStatus;
import com.android.internal.telephony.uicc.IccCardStatus;
import java.util.ArrayList;
import java.util.Collections;

/**
 * RIL customization for Galaxy S5 (GSM) LTE devices
 *
 * {@hide}
 */
public class KlteRIL extends RIL {

    private static final int RIL_REQUEST_DIAL_EMERGENCY = 10016;

    public KlteRIL(Context context, int networkMode, int cdmaSubscription) {
        super(context, networkMode, cdmaSubscription);
        mQANElements = 6;
    }

    @Override
    public void
    dial(String address, int clirMode, UUSInfo uusInfo, Message result) {
        if (PhoneNumberUtils.isEmergencyNumber(address)) {
            dialEmergencyCall(address, clirMode, result);
            return;
        }

        RILRequest rr = RILRequest.obtain(RIL_REQUEST_DIAL, result);

        rr.mParcel.writeString(address);
        rr.mParcel.writeInt(clirMode);
        rr.mParcel.writeInt(0);     // CallDetails.call_type
        rr.mParcel.writeInt(1);     // CallDetails.call_domain
        rr.mParcel.writeString(""); // CallDetails.getCsvFromExtras

        if (uusInfo == null) {
            rr.mParcel.writeInt(0); // UUS information is absent
        } else {
            rr.mParcel.writeInt(1); // UUS information is present
            rr.mParcel.writeInt(uusInfo.getType());
            rr.mParcel.writeInt(uusInfo.getDcs());
            rr.mParcel.writeByteArray(uusInfo.getUserData());
        }

        if (RILJ_LOGD) riljLog(rr.serialString() + "> " + requestToString(rr.mRequest));

        send(rr);
    }

    @Override
    protected Object
    responseIccCardStatus(Parcel p) {
        IccCardApplicationStatus appStatus;

        IccCardStatus cardStatus = new IccCardStatus();
        cardStatus.setCardState(p.readInt());
        cardStatus.setUniversalPinState(p.readInt());
        cardStatus.mGsmUmtsSubscriptionAppIndex = p.readInt();
        cardStatus.mCdmaSubscriptionAppIndex = p.readInt();
        cardStatus.mImsSubscriptionAppIndex = p.readInt();

        int numApplications = p.readInt();

        // limit to maximum allowed applications
        if (numApplications > IccCardStatus.CARD_MAX_APPS) {
            numApplications = IccCardStatus.CARD_MAX_APPS;
        }
        cardStatus.mApplications = new IccCardApplicationStatus[numApplications];

        for (int i = 0 ; i < numApplications ; i++) {
            appStatus = new IccCardApplicationStatus();
            appStatus.app_type       = appStatus.AppTypeFromRILInt(p.readInt());
            appStatus.app_state      = appStatus.AppStateFromRILInt(p.readInt());
            appStatus.perso_substate = appStatus.PersoSubstateFromRILInt(p.readInt());
            appStatus.aid            = p.readString();
            appStatus.app_label      = p.readString();
            appStatus.pin1_replaced  = p.readInt();
            appStatus.pin1           = appStatus.PinStateFromRILInt(p.readInt());
            appStatus.pin2           = appStatus.PinStateFromRILInt(p.readInt());
            p.readInt(); // pin1_num_retries
            p.readInt(); // puk1_num_retries
            p.readInt(); // pin2_num_retries
            p.readInt(); // puk2_num_retries
            p.readInt(); // perso_unblock_retries

            cardStatus.mApplications[i] = appStatus;
        }
        return cardStatus;
    }

    @Override
    protected Object
    responseCallList(Parcel p) {
        int num;
        int voiceSettings;
        ArrayList<DriverCall> response;
        DriverCall dc;

        num = p.readInt();
        response = new ArrayList<DriverCall>(num);

        if (RILJ_LOGV) {
            riljLog("responseCallList: num=" + num +
                    " mEmergencyCallbackModeRegistrant=" + mEmergencyCallbackModeRegistrant +
                    " mTestingEmergencyCall=" + mTestingEmergencyCall.get());
        }
        for (int i = 0 ; i < num ; i++) {
            dc = new DriverCall();

            dc.state = DriverCall.stateFromCLCC(p.readInt());
            dc.index = p.readInt() & 0xff;
            dc.TOA = p.readInt();
            dc.isMpty = (0 != p.readInt());
            dc.isMT = (0 != p.readInt());
            dc.als = p.readInt();
            voiceSettings = p.readInt();
            dc.isVoice = (0 == voiceSettings);
            boolean isVideo = (0 == p.readInt());   // Samsung CallDetails
            int call_type = p.readInt();            // Samsung CallDetails
            int call_domain = p.readInt();          // Samsung CallDetails
            String csv = p.readString();            // Samsung CallDetails
            dc.isVoicePrivacy = (0 != p.readInt());
            dc.number = p.readString();
            int np = p.readInt();
            dc.numberPresentation = DriverCall.presentationFromCLIP(np);
            dc.name = p.readString();
            dc.namePresentation = p.readInt();
            int uusInfoPresent = p.readInt();
            if (uusInfoPresent == 1) {
                dc.uusInfo = new UUSInfo();
                dc.uusInfo.setType(p.readInt());
                dc.uusInfo.setDcs(p.readInt());
                byte[] userData = p.createByteArray();
                dc.uusInfo.setUserData(userData);
                riljLogv(String.format("Incoming UUS : type=%d, dcs=%d, length=%d",
                                dc.uusInfo.getType(), dc.uusInfo.getDcs(),
                                dc.uusInfo.getUserData().length));
                riljLogv("Incoming UUS : data (string)="
                        + new String(dc.uusInfo.getUserData()));
                riljLogv("Incoming UUS : data (hex): "
                        + IccUtils.bytesToHexString(dc.uusInfo.getUserData()));
            } else {
                riljLogv("Incoming UUS : NOT present!");
            }

            // Make sure there's a leading + on addresses with a TOA of 145
            dc.number = PhoneNumberUtils.stringFromStringAndTOA(dc.number, dc.TOA);

            response.add(dc);

            if (dc.isVoicePrivacy) {
                mVoicePrivacyOnRegistrants.notifyRegistrants();
                riljLog("InCall VoicePrivacy is enabled");
            } else {
                mVoicePrivacyOffRegistrants.notifyRegistrants();
                riljLog("InCall VoicePrivacy is disabled");
            }
        }

        Collections.sort(response);

        if ((num == 0) && mTestingEmergencyCall.getAndSet(false)) {
            if (mEmergencyCallbackModeRegistrant != null) {
                riljLog("responseCallList: call ended, testing emergency call," +
                            " notify ECM Registrants");
                mEmergencyCallbackModeRegistrant.notifyRegistrant();
            }
        }

        return response;
    }

    @Override
    protected Object
    responseSignalStrength(Parcel p) {
        int gsmSignalStrength = p.readInt() & 0xff;
        int gsmBitErrorRate = p.readInt();
        int cdmaDbm = p.readInt();
        int cdmaEcio = p.readInt();
        int evdoDbm = p.readInt();
        int evdoEcio = p.readInt();
        int evdoSnr = p.readInt();
        int lteSignalStrength = p.readInt();
        int lteRsrp = p.readInt();
        int lteRsrq = p.readInt();
        int lteRssnr = p.readInt();
        int lteCqi = p.readInt();
        int tdScdmaRscp = p.readInt();
        // constructor sets default true, makeSignalStrengthFromRilParcel does not set it
        boolean isGsm = true;

        if ((lteSignalStrength & 0xff) == 255 || lteSignalStrength == 99) {
            lteSignalStrength = 99;
            lteRsrp = SignalStrength.INVALID;
            lteRsrq = SignalStrength.INVALID;
            lteRssnr = SignalStrength.INVALID;
            lteCqi = SignalStrength.INVALID;
        } else {
            lteSignalStrength &= 0xff;
        }

        if (RILJ_LOGD)
            riljLog("gsmSignalStrength:" + gsmSignalStrength + " gsmBitErrorRate:" + gsmBitErrorRate +
                    " cdmaDbm:" + cdmaDbm + " cdmaEcio:" + cdmaEcio + " evdoDbm:" + evdoDbm +
                    " evdoEcio: " + evdoEcio + " evdoSnr:" + evdoSnr +
                    " lteSignalStrength:" + lteSignalStrength + " lteRsrp:" + lteRsrp +
                    " lteRsrq:" + lteRsrq + " lteRssnr:" + lteRssnr + " lteCqi:" + lteCqi +
                    " tdScdmaRscp:" + tdScdmaRscp + " isGsm:" + (isGsm ? "true" : "false"));

        return new SignalStrength(gsmSignalStrength, gsmBitErrorRate, cdmaDbm, cdmaEcio, evdoDbm,
                evdoEcio, evdoSnr, lteSignalStrength, lteRsrp, lteRsrq, lteRssnr, lteCqi,
                tdScdmaRscp, isGsm);
    }

    private void
    dialEmergencyCall(String address, int clirMode, Message result) {
        RILRequest rr;

        rr = RILRequest.obtain(RIL_REQUEST_DIAL_EMERGENCY, result);
        rr.mParcel.writeString(address);
        rr.mParcel.writeInt(clirMode);
        rr.mParcel.writeInt(0);        // CallDetails.call_type
        rr.mParcel.writeInt(3);        // CallDetails.call_domain
        rr.mParcel.writeString("");    // CallDetails.getCsvFromExtra
        rr.mParcel.writeInt(0);        // Unknown

        if (RILJ_LOGD) riljLog(rr.serialString() + "> " + requestToString(rr.mRequest));

        send(rr);
    }
}
