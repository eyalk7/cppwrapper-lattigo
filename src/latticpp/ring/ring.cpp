// SPDX-License-Identifier: Apache-2.0

#include "ring.h"

using namespace std;

namespace latticpp {

    Ring newRing(uint64_t n, vector<uint64_t> moduli) {
        return Ring(lattigo_newRing(n, moduli.data(), moduli.size()));
    }

    PolyQP newPolyQP(const RingQP &ring) {
        return PolyQP(lattigo_newPolyQP(ring.getRawHandle()));
    }

    void addLvl(const RingQP &ring, uint64_t levelQ, uint64_t levelP, const PolyQP &p1, const PolyQP &p2, PolyQP &p3) {
        lattigo_ringQPAddLvl(ring.getRawHandle(), levelQ, levelP, p1.getRawHandle(), p2.getRawHandle(),
                        p3.getRawHandle());
    }

    void copy(PolyQP &pTarget, const PolyQP &pSrc) {
        lattigo_polyQPCopy(pTarget.getRawHandle(), pSrc.getRawHandle());
    }

    UniformSampler newUniformSampler(const PRNG &prng, const Ring &ring) {
        return UniformSampler(
            lattigo_newUniformSampler(prng.getRawHandle(), ring.getRawHandle()));
    }

    Poly polyQ(const PolyQP &polyQp) {
        return Poly(lattigo_polyQ(polyQp.getRawHandle()));
    }

    Poly polyP(const PolyQP &polyQp) {
        return Poly(lattigo_polyP(polyQp.getRawHandle()));
    }

    void copyLvl(uint64_t level, const Poly &sourcePoly, Poly &targetPoly) {
        lattigo_copyLvl(level, sourcePoly.getRawHandle(), targetPoly.getRawHandle());
    }

    void copyPolyAtLevel(Poly &dstPoly, uint64_t dstIndex, const Poly &srcPoly, uint64_t srcIndex) {
        lattigo_copyPolyAtLevel(dstPoly.getRawHandle(), dstIndex, srcPoly.getRawHandle(), srcIndex);
    }

    BasisExtender newBasisExtender(const Ring &ringQ, const Ring &ringP) {
        return lattigo_newBasisExtender(ringQ.getRawHandle(), ringP.getRawHandle());
    }

    void modUpQtoP(const BasisExtender &ext, uint64_t levelQ, uint64_t levelP, const Poly &polQ, Poly &polP) {
        lattigo_modUpQtoP(ext.getRawHandle(), levelQ, levelP, polQ.getRawHandle(), polP.getRawHandle());
    }

    void invNTTLvl(const RingQP &ringQP, uint64_t levelQ, uint64_t levelP, const PolyQP &pIn, PolyQP &pOut) {
        lattigo_invNTTLvlRingQP(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void nttLvl(const RingQP &ringQP, uint64_t levelQ, uint64_t levelP, const PolyQP &pIn, PolyQP &pOut) {
        lattigo_nttLvlRingQP(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void invNTTLvl(const Ring &ring, uint64_t level, const Poly &pIn, Poly &pOut) {
        lattigo_invNTTLvlRing(ring.getRawHandle(), level, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void nttLvl(const Ring &ring, uint64_t level, const Poly &pIn, Poly &pOut) {
        lattigo_nttLvlRing(ring.getRawHandle(), level, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void invMFormLvl(const RingQP &ringQP, uint64_t levelQ, uint64_t levelP, const PolyQP &pIn, PolyQP &pOut) {
        lattigo_invMFormLvlRingQP(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void mFormLvl(const RingQP &ringQP, uint64_t levelQ, uint64_t levelP, const PolyQP &pIn, PolyQP &pOut) {
       lattigo_mFormLvlRingQP(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void invMFormLvl(const Ring &ring, uint64_t level, const Poly &pIn, Poly &pOut) {
       lattigo_invMFormLvlRing(ring.getRawHandle(), level, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void mFormLvl(const Ring &ring, uint64_t level, const Poly &pIn, Poly &pOut) {
       lattigo_mFormLvlRing(ring.getRawHandle(), level, pIn.getRawHandle(), pOut.getRawHandle());
    }

    Poly newPoly(const Ring &ring){
        return Poly(lattigo_newPoly(ring.getRawHandle()));
    }

    void copyPoly(Poly &dst, const Poly &src){
        lattigo_copyPoly(dst.getRawHandle(), src.getRawHandle());
    }

    uint64_t degree(const Poly &p) { 
        return lattigo_polyDegree(p.getRawHandle()); 
    }

    uint64_t ringN(const Ring &ring) { 
        return lattigo_ringN(ring.getRawHandle()); 
    }

    vector<uint64_t> permuteNTTIndex(const Ring &ring, uint64_t galEl) {
        vector<uint64_t> res(ringN(ring));
        lattigo_permuteNTTIndex(ring.getRawHandle(), galEl, res.data());
        return res;
    }

    void permuteNTTWithIndexLvl(const Ring &ring, uint64_t level, const Poly &polyIn, const vector<uint64_t> &index, Poly &polyOut) {
        lattigo_permuteNTTWithIndexLvl(ring.getRawHandle(), level, polyIn.getRawHandle(), index.data(), polyOut.getRawHandle());
    }

    uint64_t log2OfInnerSum(uint64_t level, const Ring &ring, const Poly &poly){
        return lattigo_log2OfInnerSum(level, ring.getRawHandle(), poly.getRawHandle());
    }

    void mulCoeffsMontgomeryAndAddLvl(const RingQP &ringQP, uint64_t levelQ, uint64_t levelP, const PolyQP &p1, const PolyQP &p2, const PolyQP &p3) {
        lattigo_mulCoeffsMontgomeryAndAddLvl(ringQP.getRawHandle(),levelQ, levelP, p1.getRawHandle(),p2.getRawHandle(),p3.getRawHandle());
    }

    void mulCoeffsMontgomeryAndAddLvl(const Ring &ring, uint64_t level, const Poly &p1, const Poly &p2, const Poly &p3) {
        lattigo_mulCoeffsMontgomeryAndAddLvlRing(ring.getRawHandle(),level, p1.getRawHandle(),p2.getRawHandle(),p3.getRawHandle());
    }

    uint64_t equals(const Poly &p1, const Poly &p2){
        return lattigo_equals(p1.getRawHandle(), p2.getRawHandle());
    }

} // namespace latticpp