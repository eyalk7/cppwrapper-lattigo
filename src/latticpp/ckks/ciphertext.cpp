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
        // a handle of 0 is an invalid Go reference (my equivalent of a nil/null pointer)
        if (ct.getRawHandle() == 0) {
            return ct;
        }
        return lattigo_copyNew(ct.getRawHandle());
    }

    CiphertextQP copyNew(const CiphertextQP &ctQP) {
        // a handle of 0 is an invalid Go reference (my equivalent of a nil/null pointer)
        if (ctQP.getRawHandle() == 0) {
            return ctQP;
        }
        return lattigo_copyNewCiphertextQP(ctQP.getRawHandle());
    }

    Ciphertext newCiphertext(const Parameters &params, uint64_t degree, uint64_t level) {
        return Ciphertext(lattigo_newCiphertext(params.getRawHandle(), degree, level));
    }

    CiphertextQP newCiphertextQP(const Parameters &params) {
        return CiphertextQP(lattigo_newCiphertextQP(params.getRawHandle()));
    }


    void set(const Ciphertext &ctx, MetaData &metaData) {
      lattigo_setCiphertextMetaData(ctx.getRawHandle(), metaData.getRawHandle());
    }

    void set(const CiphertextQP &ctx, MetaData &metaData) {
      lattigo_setCiphertextQPMetaData(ctx.getRawHandle(), metaData.getRawHandle());
    }

    MetaData getMetaData(const CiphertextQP &ctxQP) {
      return lattigo_getCiphertextQPMetaData(ctxQP.getRawHandle());
    }

    MetaData getMetaData(const Ciphertext &ctx) {
      return lattigo_getCiphertextMetaData(ctx.getRawHandle());
    }

    Poly poly(const Ciphertext &ctx, uint64_t i) {
      return lattigo_poly(ctx.getRawHandle(), i);
    }

    PolyQP polyQP(const CiphertextQP &ctQP, uint64_t i) {
      return lattigo_polyQPCiphertextQP(ctQP.getRawHandle(), i);
    }
    

    CiphertextQP newZeroCiphertextQP(const Parameters &params, const SecretKey &sk){
      return lattigo_newZeroCiphertextQP(params.getRawHandle(), sk.getRawHandle());
    }

    Ciphertext newZeroCiphertext(const Parameters &params, const SecretKey &sk){
      return lattigo_newZeroCiphertext(params.getRawHandle(), sk.getRawHandle());
    }

    void printMetaData(const CiphertextQP &ctQP){
      lattigo_printMetaCtQP(ctQP.getRawHandle());
    }

    void printMetaData(const Ciphertext &ct){
      lattigo_printMetaCt(ct.getRawHandle());
    }

    void printMetaData(const Plaintext &pt){
      lattigo_printMetaPt(pt.getRawHandle());
    }

    

}  // namespace latticpp