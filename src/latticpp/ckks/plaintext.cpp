// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#include "plaintext.h"

namespace latticpp {
    
    Plaintext newPlaintext(const Parameters &params, const Poly &poly, uint64_t level){
        return Plaintext(lattigo_newPlaintext(params.getRawHandle(), poly.getRawHandle(), level));
    }

    Poly poly(const Plaintext &plaintext) {
        return Poly(lattigo_getPlaintextPoly(plaintext.getRawHandle()));
    }

}  // namespace latticpp