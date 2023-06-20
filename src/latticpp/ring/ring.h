// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "cgo/ring.h"
#include "latticpp/marshal/gohandle.h"
#include <vector>

namespace latticpp {

    Ring newRing(uint64_t n, std::vector<uint64_t> moduli);

    PolyQP newPolyQP(const RingQP &ring);

    void addLvl(const RingQP &ring, uint64_t levelQ, uint64_t levelP, const PolyQP &p1, const PolyQP &p2, PolyQP &p3);

    void copy(PolyQP &pTarget, const PolyQP &pSrc);

    UniformSampler newUniformSampler(const PRNG &prng, const Ring &ring);

    Poly readNewFromSampler(const UniformSampler &sampler);

    Poly polyQ(const PolyQP &polyqp);

    Poly polyP(const PolyQP &polyqp);

    void copyLvl(uint64_t level, const Poly sourcePoly, Poly targetPoly);

    void copyPolyAtLevel(const Poly dstPoly, uint64_t dstIndex, Poly srcPoly, uint64_t srcIndex);

    BasisExtender newBasisExtender(Ring ringQ, Ring ringP);

    void modUpQtoP(BasisExtender ext, int levelQ, int levelP, Poly polQ, Poly polP);

    void invNTTLvl(RingQP ringqp, int levelQ, int levelP, PolyQP pIn, PolyQP pOut);

    void nTTLvl(RingQP ringqp, int levelQ, int levelP, PolyQP pIn, PolyQP pOut);

    void invNTTLvl(Ring ring, int level, Poly pIn, Poly pOut);

    void nTTLvl(Ring ring, int level, Poly pIn, Poly pOut);

    void invMFormLvl(RingQP ringqp, int levelQ, int levelP, PolyQP pIn, PolyQP pOut);

    void mFormLvl(RingQP ringqp, int levelQ, int levelP, PolyQP pIn, PolyQP pOut);

    void invMFormLvl(Ring ring, int level, Poly pIn, Poly pOut);

    void mFormLvl(Ring ring, int level, Poly pIn, Poly pOut);

    uint64_t degree(Poly p);

    uint64_t N(Ring ring);

    std::vector<uint64_t> permuteNTTIndex(Ring ring, uint64_t galEl);

    void permuteNTTWithIndexLvl(Ring ring, uint64_t level, Poly polyIn, const std::vector<uint64_t> &index, Poly polyOut);

    int log2OfInnerSum(int level, Ring ring, Poly poly);

	// MulCoeffsMontgomeryAndAddLvl multiplies p1 by p2 coefficient-wise with a Montgomery
	// modular reduction for the moduli from q_0 up to q_level and adds the result to p3.
    void mulCoeffsMontgomeryAndAddLvl(RingQP ringQP, int levelQ, int levelP, PolyQP p1, PolyQP p2, PolyQP p3);

    void mulCoeffsMontgomeryAndAddLvl(Ring ring, int level, Poly p1, Poly p2, Poly p3);

    int equals(const Poly &p1, const Poly &p2);

    void print(const Poly &p);
    
} // namespace latticpp