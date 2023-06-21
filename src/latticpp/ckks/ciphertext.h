// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "latticpp/marshal/gohandle.h"
#include "cgo/ciphertext.h"

namespace latticpp {

    uint64_t level(const Ciphertext &ct);

    double scale(const Ciphertext &ct);

    uint64_t degree(const Ciphertext &ct);

    Ciphertext copyNew(const Ciphertext &ct);

    CiphertextQP copyNew(const CiphertextQP &ctQP);

    Ciphertext newCiphertext(const Parameters &params, uint64_t degree, uint64_t level);

    CiphertextQP newCiphertextQP(const Parameters &params);

    void set(Ciphertext &ctx, const MetaData &metaData);

    void set(CiphertextQP &ctx, const MetaData &metaData);

    MetaData getMetaData(const CiphertextQP &ctxQP);

    MetaData getMetaData(const Ciphertext &ctx);

    Poly poly(const Ciphertext &ctx, uint64_t i);

    PolyQP polyQP(const CiphertextQP &ctQP, uint64_t i);

}  // namespace latticpp