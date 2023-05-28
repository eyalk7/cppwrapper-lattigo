// SPDX-License-Identifier: Apache-2.0

#include "ring.h"

using namespace std;

namespace latticpp {

Ring newRing(uint64_t n, vector<uint64_t> moduli) {
  return Ring(lattigo_newRing(n, moduli.data(), moduli.size()));
}

Poly newPoly(const Ring &ring) {
  return Poly(lattigo_newPoly(ring.getRawHandle()));
}

void add(const Ring &ring, const Poly &p1, const Poly &p2, Poly &p3) {
  lattigo_ringAdd(ring.getRawHandle(), p1.getRawHandle(), p2.getRawHandle(),
                  p3.getRawHandle());
}

void copy(Poly &pTarget, const Poly &pSrc) {
  lattigo_polyCopy(pTarget.getRawHandle(), pSrc.getRawHandle());
}

UniformSampler newUniformSampler(const PRNG &prng, const Ring &ring) {
  return UniformSampler(
      lattigo_newUniformSampler(prng.getRawHandle(), ring.getRawHandle()));
}

Poly readNewFromSampler(const UniformSampler &sampler) {
  return Poly(lattigo_readNewFromSampler(sampler.getRawHandle()));
}

Poly getQ(const PolyQP &polyqp) {
  return Poly(lattigo_getQ(polyqp.getRawHandle()));
}

Poly getP(const PolyQP &polyqp) {
  return Poly(lattigo_getP(polyqp.getRawHandle()));
}

void copyPoly(Poly targetPoly, const Poly sourcePoly) {
  lattigo_copyPoly(sourcePoly.getRawHandle(), targetPoly.getRawHandle());
}

void copyLvl(uint64_t level, const Poly sourcePoly, Poly targetPoly) {
  lattigo_copyLvl(level, sourcePoly.getRawHandle(), targetPoly.getRawHandle());
}

void copyPolyRnsLevel(const Poly sourcePoly, uint64_t sourceIndex,
                      Poly targetPoly, uint64_t targetIndex) {
  lattigo_copyPolyRnsLevel(sourcePoly.getRawHandle(), sourceIndex,
                           targetPoly.getRawHandle(), targetIndex);
}

BasisExtender newBasisExtender(Ring ringQ, Ring ringP) {
  return lattigo_newBasisExtender(ringQ.getRawHandle(), ringP.getRawHandle());
}

void modUpQtoP(BasisExtender ext, int levelQ, int levelP, Poly polQ,
               Poly polP) {
  lattigo_modUpQtoP(ext.getRawHandle(), levelQ, levelP, polQ.getRawHandle(),
                    polP.getRawHandle());
}

void invNTTLvl(RingQP ringQP, int levelQ, int levelP, PolyQP pIn, PolyQP pOut) {
  lattigo_invNTTLvl(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(),
                    pOut.getRawHandle());
}

void nTTLvl(RingQP ringQP, int levelQ, int levelP, PolyQP pIn, PolyQP pOut) {
  lattigo_nTTLvl(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(),
                 pOut.getRawHandle());
}

void invMFormLvl(RingQP ringQP, int levelQ, int levelP, PolyQP pIn,
                 PolyQP pOut) {
  lattigo_invMFormLvl(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(),
                      pOut.getRawHandle());
}

void mFormLvl(RingQP ringQP, int levelQ, int levelP, PolyQP pIn, PolyQP pOut) {
  lattigo_mFormLvl(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(),
                   pOut.getRawHandle());
}

} // namespace latticpp
