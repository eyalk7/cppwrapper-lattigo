// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#include "ciphertext.h"

namespace latticpp {

uint64_t level(const Ciphertext &ct) {
  return lattigo_level(ct.getRawHandle());
}

double scale(const Ciphertext &ct) {
  return lattigo_ciphertextScale(ct.getRawHandle());
}

uint64_t degree(const Ciphertext &ct) {
  return lattigo_ciphertextDegree(ct.getRawHandle());
}

Ciphertext copyNew(const Ciphertext &ct) {
  // a handle of 0 is an invalid Go reference (my equivalent of a nil/null
  // pointer)
  if (ct.getRawHandle() == 0) {
    return ct;
  }
  return lattigo_copyNew(ct.getRawHandle());
}

Ciphertext newCiphertext(const Parameters &params, uint64_t degree,
                         uint64_t level) {
  return Ciphertext(
      lattigo_newCiphertext(params.getRawHandle(), degree, level));
}

void setCiphertextMetaData(const Ciphertext &ctx, MetaData &metaData) {
  lattigo_setCiphertextMetaData(ctx.getRawHandle(), metaData.getRawHandle());
}

MetaData getCiphertextQPMetaData(const CiphertextQP &ctxQP) {
  return lattigo_getCiphertextQPMetaData(ctxQP.getRawHandle());
}

Poly poly(const Ciphertext &ctx, uint64_t i) {
  return lattigo_poly(ctx.getRawHandle(), i);
}

} // namespace latticpp
