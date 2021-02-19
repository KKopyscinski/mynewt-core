/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef __SHA256_ALT_H__
#define __SHA256_ALT_H__

#include <os/mynewt.h>

#if MYNEWT_VAL(MBEDTLS_SHA256_ALT)

#ifdef __cplusplus
extern "C" {
#endif

#include <hash/hash.h>

typedef struct mbedtls_sha256_context {
    struct hash_dev *hash;
    struct hash_sha256_context sha256ctx;
} mbedtls_sha256_context;

void mbedtls_sha256_init(mbedtls_sha256_context *ctx);
void mbedtls_sha256_free(mbedtls_sha256_context *ctx);
void mbedtls_sha256_clone(mbedtls_sha256_context *dst,
                          const mbedtls_sha256_context *src);
int mbedtls_sha256_starts_ret(mbedtls_sha256_context *ctx, int is224);
int mbedtls_sha256_update_ret(mbedtls_sha256_context *ctx,
                              const unsigned char *input, size_t ilen);
int mbedtls_sha256_finish_ret(mbedtls_sha256_context *ctx,
                              unsigned char output[32]);
int mbedtls_internal_sha256_process(mbedtls_sha256_context *ctx,
                                    const unsigned char data[64]);

/*
 * XXX deprecated functions
 */
void mbedtls_sha256_starts(mbedtls_sha256_context *ctx, int is224);
void mbedtls_sha256_update(mbedtls_sha256_context *ctx,
        const unsigned char *input, size_t ilen);
void mbedtls_sha256_finish(mbedtls_sha256_context *ctx,
        unsigned char output[32]);

#ifdef __cplusplus
}
#endif

#endif /* MYNEWT_VAL(MBEDTLS_SHA256_ALT) */

#endif /* __SHA256_ALT_H__ */
