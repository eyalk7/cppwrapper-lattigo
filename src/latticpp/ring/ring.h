// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "cgo/ring.h"
#include "latticpp/marshal/gohandle.h"
#include <vector>

namespace latticpp {

Ring newRing(uint64_t n, std::vector<uint64_t> moduli);

Poly newPoly(const Ring &ring);

void add(const Ring &ring, const Poly &p1, const Poly &p2, Poly &p3);

void copy(Poly &pTarget, const Poly &pSrc);

UniformSampler newUniformSampler(const PRNG &prng, const Ring &ring);

Poly readNewFromSampler(const UniformSampler &sampler);

Poly getQ(const PolyQP &polyqp);

Poly getP(const PolyQP &polyqp);

void copyPoly(Poly targetPoly, const Poly sourcePoly);

void copyLvl(uint64_t level, const Poly sourcePoly, Poly targetPoly);

void copyPolyRnsLevel(const Poly sourcePoly, uint64_t sourceIndex,
                      const Poly targetPoly, uint64_t targetIndex);

BasisExtender newBasisExtender(Ring ringQ, Ring ringP);

void modUpQtoP(BasisExtender ext, int levelQ, int levelP, Poly polQ, Poly polP);

void invNTTLvl(RingQP ringqp, int levelQ, int levelP, PolyQP pIn, PolyQP pOut);

void nTTLvl(RingQP ringqp, int levelQ, int levelP, PolyQP pIn, PolyQP pOut);

void invMFormLvl(RingQP ringqp, int levelQ, int levelP, PolyQP pIn,
                 PolyQP pOut);

void mFormLvl(RingQP ringqp, int levelQ, int levelP, PolyQP pIn, PolyQP pOut);
} // namespace latticpp
