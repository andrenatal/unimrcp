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

#ifndef __MPF_NAMED_EVENT_H__
#define __MPF_NAMED_EVENT_H__

/**
 * @file mpf_named_event.h
 * @brief MPF Named Events (RFC4733/RFC2833)
 */ 

#include "mpf_codec_descriptor.h"

APT_BEGIN_EXTERN_C

/** Named event declaration */
typedef struct mpf_named_event_frame_t mpf_named_event_frame_t;


/** Named event (RFC4733/RFC2833, out-of-band DTMF) */
struct mpf_named_event_frame_t {
	/** event (DTMF, tone) identifier */
	apr_uint32_t event_id: 8;
#if (APR_IS_BIGENDIAN == 1)
	/** end of event */
	apr_uint32_t edge:     1;
	/** reserved */
	apr_uint32_t reserved: 1;
	/** tone volume */
	apr_uint32_t volume:   6;
#else
	/** tone volume */
	apr_uint32_t volume:   6;
	/** reserved */
	apr_uint32_t reserved: 1;
	/** end of event */
	apr_uint32_t edge:     1;
#endif
	/** event duration */
	apr_uint32_t duration: 16;
};

mpf_codec_descriptor_t* mpf_event_descriptor_create(apr_uint16_t sampling_rate, apr_pool_t *pool);


APT_END_EXTERN_C

#endif /*__MPF_NAMED_EVENT_H__*/
