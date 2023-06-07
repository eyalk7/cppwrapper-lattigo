// SPDX-License-Identifier: Apache-2.0

#include "ring.h"

using namespace std;
using namespace latticpp;

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

Poly polyQ(const PolyQP &polyqp) {
  return Poly(lattigo_polyQ(polyqp.getRawHandle()));
}

Poly polyP(const PolyQP &polyqp) {
  return Poly(lattigo_polyP(polyqp.getRawHandle()));
}

void copyLvl(uint64_t level, const Poly sourcePoly, Poly targetPoly) {
  lattigo_copyLvl(level, sourcePoly.getRawHandle(), targetPoly.getRawHandle());
}

void copyPolySingleLevel(const Poly sourcePoly, uint64_t sourceIndex,
                         Poly targetPoly, uint64_t targetIndex) {
  lattigo_copyPolySingleLevel(sourcePoly.getRawHandle(), sourceIndex,
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
  lattigo_invMFormLvlRingQP(ringQP.getRawHandle(), levelQ, levelP,
                            pIn.getRawHandle(), pOut.getRawHandle());
}

void mFormLvl(RingQP ringQP, int levelQ, int levelP, PolyQP pIn, PolyQP pOut) {
  lattigo_mFormLvlRingQP(ringQP.getRawHandle(), levelQ, levelP,
                         pIn.getRawHandle(), pOut.getRawHandle());
}

void invMFormLvl(Ring ring, int level, Poly pIn, Poly pOut) {
  lattigo_invMFormLvlRing(ring.getRawHandle(), level, pIn.getRawHandle(),
                          pOut.getRawHandle());
}

void mFormLvl(Ring ring, int level, Poly pIn, Poly pOut) {
  lattigo_mFormLvlRing(ring.getRawHandle(), level, pIn.getRawHandle(),
                       pOut.getRawHandle());
}

uint64_t degree(Poly p) { return lattigo_polyDegree(p.getRawHandle()); }

uint64_t N(Ring ring) { return lattigo_N(ring.getRawHandle()); }

vector<uint64_t> permuteNTTIndex(Ring ring, uint64_t galEl) {
  vector<uint64_t> res(N(ring));
  lattigo_permuteNTTIndex(ring.getRawHandle(), galEl, res.data());
  return res;
}

void permuteNTTWithIndexLvl(Ring ring, uint64_t level, Poly polyIn,
                            const vector<uint64_t> &index, Poly polyOut) {
  lattigo_permuteNTTWithIndexLvl(ring.getRawHandle(), level,
                                 polyIn.getRawHandle(), index.data(),
                                 polyOut.getRawHandle());
}

} // namespace latticpp
