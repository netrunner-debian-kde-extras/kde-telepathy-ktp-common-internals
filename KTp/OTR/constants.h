/***************************************************************************
 *   Copyright (C) 2014 by Marcin Ziemiński <zieminn@gmail.com>            *
 *                                                                         *
 * This library is free software; you can redistribute it and/or           *
 * modify it under the terms of the GNU Lesser General Public		   *
 * License as published by the Free Software Foundation; either		   *
 * version 2.1 of the License, or (at your option) any later version.	   *
 * 									   *
 * This library is distributed in the hope that it will be useful,	   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of	   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU	   *
 * Lesser General Public License for more details.			   *
 * 									   *
 * You should have received a copy of the GNU Lesser General Public	   *
 * License along with this library; if not, write to the Free Software	   *
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA*
 ***************************************************************************/

#ifndef KTP_OTR_CONSTANTS_HEADER
#define KTP_OTR_CONSTANTS_HEADER

namespace KTp
{
/**
 * \enum OTRTrustLevel
 * \ingroup enumtypeconsts
 *
 * Enumerated type generated from the specification.
 *
 * Enumeration describing trust level of this conversation. The trust level
 * can only increase unless Initialize/Stop are called or TrustFingerprint is
 * called with trust=false.
 */
enum OTRTrustLevel
{
    /**
     * The conversation is currently unencrypted
     */
    OTRTrustLevelNotPrivate = 0,

    /**
     * The conversation is currently encrypted but the remote end is not
     * verified
     */
    OTRTrustLevelUnverified = 1,

    /**
     * The conversation is currently encrypted and the remote end is verified
     */
    OTRTrustLevelPrivate = 2,

    /**
     * Remote end closed the OTR session, messages cannot be sent anymore.
     * Either call Stop to continue unencrypted or Initialize to send
     * encrypted messages again.
     */
    OTRTrustLevelFinished = 3,

    _OTRTrustLevelPadding = 0xffffffffU
};

/**
 * \ingroup enumtypeconsts
 *
 * 1 higher than the highest valid value of OTRTrustLevel.
 */
const int NUM_OTR_TRUST_LEVELS = (3+1);

enum OTRPolicy {
    OTRPolicyAlways = 0,
    OTRPolicyOpportunistic = 1,
    OTRPolicyManual = 2,
    OTRPolicyNever = 3
};


/**
 * OTR message event enum type - the same as OtrlMessageEvent in libotr
 */
enum OTRMessageEvent
{
    OTRL_MSGEVENT_NONE,
    OTRL_MSGEVENT_ENCRYPTION_REQUIRED,
    OTRL_MSGEVENT_ENCRYPTION_ERROR,
    OTRL_MSGEVENT_CONNECTION_ENDED,
    OTRL_MSGEVENT_SETUP_ERROR,
    OTRL_MSGEVENT_MSG_REFLECTED,
    OTRL_MSGEVENT_MSG_RESENT,
    OTRL_MSGEVENT_RCVDMSG_NOT_IN_PRIVATE,
    OTRL_MSGEVENT_RCVDMSG_UNREADABLE,
    OTRL_MSGEVENT_RCVDMSG_MALFORMED,
    OTRL_MSGEVENT_LOG_HEARTBEAT_RCVD,
    OTRL_MSGEVENT_LOG_HEARTBEAT_SENT,
    OTRL_MSGEVENT_RCVDMSG_GENERAL_ERR,
    OTRL_MSGEVENT_RCVDMSG_UNENCRYPTED,
    OTRL_MSGEVENT_RCVDMSG_UNRECOGNIZED,
    OTRL_MSGEVENT_RCVDMSG_FOR_OTHER_INSTANCE
};

}

#define KTP_PROXY_BUS_NAME (QLatin1String("org.freedesktop.Telepathy.Client.KTp.Proxy"))
#define KTP_PROXY_SERVICE_OBJECT_PATH (QLatin1String("/org/freedesktop/TelepathyProxy/ProxyService"))
#define KTP_PROXY_CHANNEL_OBJECT_PATH_PREFIX (QLatin1String("/org/freedesktop/TelepathyProxy/OtrChannelProxy/"))

#define KTP_IFACE_CHANNEL_PROXY_OTR (QLatin1String("org.kde.TelepathyProxy.ChannelProxy.Interface.OTR"))
#define KTP_IFACE_PROXY_SERVICE (QLatin1String("org.kde.TelepathyProxy.ProxyService"))

#define KTP_PROXY_ERROR_NOT_CONNECTED (QLatin1String("org.freedesktop.TelepathyProxy.Error.NotConnected"))
#define KTP_PROXY_ERROR_ENCRYPTION_ERROR (QLatin1String("org.freedesktop.TelepathyProxy.Error.EncryptionError"))

/**
 * OTR message headers
 */
#define OTR_MESSAGE_EVENT_HEADER       (QLatin1String("otr-message-event"))
#define OTR_REMOTE_FINGERPRINT_HEADER  (QLatin1String("otr-remote-fingerprint"))
#define OTR_ERROR_HEADER               (QLatin1String("otr-error"))
#define OTR_UNENCRYPTED_MESSAGE_HEADER (QLatin1String("otr-unencrypted-message"))

#endif
