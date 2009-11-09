/*
 * Copyright 2008 Arsen Chaloyan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MPF_RTP_STAT_H__
#define __MPF_RTP_STAT_H__

/**
 * @file mpf_rtp_stat.h
 * @brief RTP Statistics
 */ 

#include "mpf.h"

APT_BEGIN_EXTERN_C

/** RTP transmitter statistics */
typedef struct rtp_tx_stat_t rtp_tx_stat_t;
/** RTP receiver statistics */
typedef struct rtp_rx_stat_t rtp_rx_stat_t;

/** RTCP statistics used in Sender Report (SR) */
typedef struct rtcp_sr_stat_t rtcp_sr_stat_t;
/** RTCP statistics used in Receiver Report (RR) */
typedef struct rtcp_rr_stat_t rtcp_rr_stat_t;


/** RTP transmitter statistics */
struct rtp_tx_stat_t {
	/** number of RTP packets received */
	apr_uint32_t    sent_packets;

	/* more to come */
};

/** RTP receiver statistics */
struct rtp_rx_stat_t {
	/** number of valid RTP packets received */
	apr_uint32_t           received_packets;
	/** number of invalid RTP packets received */
	apr_uint32_t           invalid_packets;

	/** number of discarded in jitter buffer packets */
	apr_uint32_t           discarded_packets;
	/** number of ignored packets */
	apr_uint32_t           ignored_packets;

	/** number of lost in network packets */
	apr_uint32_t           lost_packets;

	/** number of restarts */
	apr_byte_t             restarts;

	/** network jitter (RFC3550) */
	apr_uint32_t           jitter;

	/** source id of received RTP stream */
	apr_uint32_t           ssrc;
};

/** RTCP statistics used in Sender Report (SR)  */
struct rtcp_sr_stat {
	/** sender source identifier */
	apr_uint32_t ssrc;
	/** NTP timestamp */
	apr_uint64_t ntp_timestamp;
	/** RTP timestamp */
	apr_uint32_t rtp_ts;
	/* packets sent */
	apr_uint32_t sent_packets;
	/* octets (bytes) sent */
	apr_uint32_t sent_octets;
};

/** RTCP statistics used in Receiver Report (RR) */
struct rtcp_rr_stat_t {
	/** data source being reported */
	apr_uint32_t ssrc;
	/** fraction lost since last SR/RR */
	apr_uint32_t fraction:8;
	/** cumulative number of packets lost (signed!) */
	apr_int32_t  lost:24;
	/** extended last sequence number received */
	apr_uint32_t last_seq;
	/** interarrival jitter */
	apr_uint32_t jitter;
	/** last SR packet from this source */
	apr_uint32_t lsr;
	/** delay since last SR packet */
	apr_uint32_t dlsr;
};



/** Reset RTP transmitter statistics */
static APR_INLINE void mpf_rtp_tx_stat_reset(rtp_tx_stat_t *tx_stat)
{
	memset(tx_stat,0,sizeof(rtp_tx_stat_t));
}

/** Reset RTP receiver statistics */
static APR_INLINE void mpf_rtp_rx_stat_reset(rtp_rx_stat_t *rx_stat)
{
	memset(rx_stat,0,sizeof(rtp_rx_stat_t));
}

APT_END_EXTERN_C

#endif /*__MPF_RTP_STAT_H__*/
