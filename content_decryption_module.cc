// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content_decryption_module.h"

namespace cdm {

SubsampleEntry::SubsampleEntry() : clear_bytes(0), cipher_bytes(0) {}

SubsampleEntry::SubsampleEntry(uint32_t clear_bytes, uint32_t cipher_bytes)
    : clear_bytes(clear_bytes), cipher_bytes(cipher_bytes) {}

InputBuffer::InputBuffer()
    : data(nullptr),
      data_size(0),
      key_id(nullptr),
      key_id_size(0),
      iv(nullptr),
      iv_size(0),
      subsamples(nullptr),
      num_subsamples(0),
      timestamp(0) {}

InputBuffer::InputBuffer(const uint8_t* data,
                         uint32_t data_size,
                         const uint8_t* key_id,
                         uint32_t key_id_size,
                         const uint8_t* iv,
                         uint32_t iv_size,
                         const struct SubsampleEntry* subsamples,
                         uint32_t num_subsamples,
                         int64_t timestamp)
    : data(data),
      data_size(data_size),
      key_id(key_id),
      key_id_size(key_id_size),
      iv(iv),
      iv_size(iv_size),
      subsamples(subsamples),
      num_subsamples(num_subsamples),
      timestamp(timestamp) {}

AudioDecoderConfig::AudioDecoderConfig()
    : codec(kUnknownAudioCodec),
      channel_count(0),
      bits_per_channel(0),
      samples_per_second(0),
      extra_data(nullptr),
      extra_data_size(0) {}

AudioDecoderConfig::AudioDecoderConfig(AudioCodec codec,
                                       int32_t channel_count,
                                       int32_t bits_per_channel,
                                       int32_t samples_per_second,
                                       uint8_t* extra_data,
                                       uint32_t extra_data_size)
    : codec(codec),
      channel_count(channel_count),
      bits_per_channel(bits_per_channel),
      samples_per_second(samples_per_second),
      extra_data(extra_data),
      extra_data_size(extra_data_size) {}

Size::Size() : width(0), height(0) {}

Size::Size(int32_t width, int32_t height) : width(width), height(height) {}

VideoDecoderConfig::VideoDecoderConfig()
    : codec(kUnknownVideoCodec),
      profile(kUnknownVideoCodecProfile),
      format(kUnknownVideoFormat),
      extra_data(nullptr),
      extra_data_size(0) {}

VideoDecoderConfig::VideoDecoderConfig(VideoCodec codec,
                                       VideoCodecProfile profile,
                                       VideoFormat format,
                                       Size coded_size,
                                       uint8_t* extra_data,
                                       uint32_t extra_data_size)
    : codec(codec),
      profile(profile),
      format(format),
      coded_size(coded_size),
      extra_data(extra_data),
      extra_data_size(extra_data_size) {}

PlatformChallengeResponse::PlatformChallengeResponse()
    : signed_data(nullptr),
      signed_data_length(0),
      signed_data_signature(nullptr),
      signed_data_signature_length(0),
      platform_key_certificate(nullptr),
      platform_key_certificate_length(0) {}

PlatformChallengeResponse::PlatformChallengeResponse(
    const uint8_t* signed_data,
    uint32_t signed_data_length,
    const uint8_t* signed_data_signature,
    uint32_t signed_data_signature_length,
    const uint8_t* platform_key_certificate,
    uint32_t platform_key_certificate_length)
    : signed_data(signed_data),
      signed_data_length(signed_data_length),
      signed_data_signature(signed_data_signature),
      signed_data_signature_length(signed_data_signature_length),
      platform_key_certificate(platform_key_certificate),
      platform_key_certificate_length(platform_key_certificate_length) {}

BinaryData::BinaryData() : data(nullptr), length(0) {}

BinaryData::BinaryData(const uint8_t* data, uint32_t length)
    : data(data), length(length) {}

KeyInformation::KeyInformation()
    : key_id(nullptr), key_id_size(0), status(kInternalError), system_code(0) {}

KeyInformation::KeyInformation(const uint8_t* key_id,
                               uint32_t key_id_size,
                               KeyStatus status,
                               uint32_t system_code)
    : key_id(key_id),
      key_id_size(key_id_size),
      status(status),
      system_code(system_code) {}

Policy::Policy() : min_hdcp_version(kHdcpVersionNone) {}

Policy::Policy(HdcpVersion min_hdcp_version)
    : min_hdcp_version(min_hdcp_version) {}

}  // namespace cdm
