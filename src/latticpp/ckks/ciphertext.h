// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "cgo/ciphertext.h"
#include "latticpp/marshal/gohandle.h"

namespace latticpp {

uint64_t level(const Ciphertext &ct);

double scale(const Ciphertext &ct);

uint64_t dergree(const Ciphertext &ct);

Ciphertext copyNew(const Ciphertext &ct);

Ciphertext newCiphertext(const Parameters &params, uint64_t degree,
                         uint64_t level);

void setCiphertextMetaData(const Ciphertext &ctx, MetaData &metaData);

MetaData getCiphertextQPMetaData(const CiphertextQP &ctxQP);

Poly poly(const Ciphertext &ctx, uint64_t i);

} // namespace latticpp
