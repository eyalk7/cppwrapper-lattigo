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

    void set(const Ciphertext &ctx, MetaData &metaData);

    void set(const CiphertextQP &ctx, MetaData &metaData);

    MetaData getMetaData(const CiphertextQP &ctxQP);

    MetaData getMetaData(const Ciphertext &ctx);

    Poly poly(const Ciphertext &ctx, uint64_t i);

    PolyQP polyQP(const CiphertextQP &ctQP, uint64_t i);

    CiphertextQP newZeroCiphertextQP(const Parameters &params, const SecretKey &sk);

    void printMetaData(const CiphertextQP &ctQP);

    void printMetaData(const Ciphertext &ct);

    void printMetaData(const Plaintext &pt);


}  // namespace latticpp