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

    Poly polyQ(const PolyQP &polyqp);

    Poly polyP(const PolyQP &polyqp);

    void copyLvl(uint64_t level, const Poly sourcePoly, Poly targetPoly);

    void copyPolyAtLevel(const Poly dstPoly, uint64_t dstIndex, Poly srcPoly, uint64_t srcIndex);

    BasisExtender newBasisExtender(const Ring &ringQ, const Ring &ringP);

    void modUpQtoP(const BasisExtender &ext, int levelQ, int levelP, const Poly &polQ, Poly &polP);

    void invNTTLvl(const RingQP &ringqp, int levelQ, int levelP, const PolyQP &pIn, PolyQP &pOut);

    void nTTLvl(const RingQP &ringqp, int levelQ, int levelP, const PolyQP &pIn, PolyQP &pOut);

    void invNTTLvl(const Ring &ring, int level, const Poly &pIn, Poly &pOut);

    void nTTLvl(const Ring &ring, int level, const Poly &pIn, Poly &pOut);

    void invMFormLvl(const RingQP &ringqp, int levelQ, int levelP, const PolyQP &pIn, PolyQP &pOut);

    void mFormLvl(const RingQP &ringqp, int levelQ, int levelP, const PolyQP &pIn, PolyQP &pOut);

    void invMFormLvl(const Ring &ring, int level, const Poly &pIn, Poly &pOut);

    void mFormLvl(const Ring &ring, int level, const Poly &pIn, Poly &pOut);

    Poly newPoly(const Ring &ring);

    void copyPoly(Poly &dst, const Poly &src);

    uint64_t degree(const Poly &p);

    uint64_t N(const Ring &ring);

    std::vector<uint64_t> permuteNTTIndex(const Ring &ring, uint64_t galEl);

    void permuteNTTWithIndexLvl(const Ring &ring, uint64_t level, const Poly &polyIn, const std::vector<uint64_t> &index, const Poly &polyOut);

    int log2OfInnerSum(int level, const Ring &ring, const Poly &poly);

    void mulCoeffsMontgomeryAndAddLvl(const RingQP &ringQP, int levelQ, int levelP, const PolyQP &p1, const PolyQP &p2, const PolyQP &p3);

    void mulCoeffsMontgomeryAndAddLvl(const Ring &ring, int level, const Poly &p1, const Poly &p2, const Poly &p3);

    int equals(const Poly &p1, const Poly &p2);

    void print(const Poly &p);
    
} // namespace latticpp