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

    Poly polyQ(const PolyQP &polyqp) {
        return Poly(lattigo_polyQ(polyqp.getRawHandle()));
    }

    Poly polyP(const PolyQP &polyqp) {
        return Poly(lattigo_polyP(polyqp.getRawHandle()));
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

    void modUpQtoP(const BasisExtender &ext, int levelQ, int levelP, const Poly &polQ, Poly &polP) {
        lattigo_modUpQtoP(ext.getRawHandle(), levelQ, levelP, polQ.getRawHandle(), polP.getRawHandle());
    }

    void invNTTLvl(const RingQP &ringQP, int levelQ, int levelP, const PolyQP &pIn, PolyQP &pOut) {
        lattigo_invNTTLvlRingQP(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void nTTLvl(const RingQP &ringQP, int levelQ, int levelP, const PolyQP &pIn, PolyQP &pOut) {
        lattigo_nTTLvlRingQP(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void invNTTLvl(const Ring &ring, int level, const Poly &pIn, Poly &pOut) {
        lattigo_invNTTLvlRing(ring.getRawHandle(), level, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void nTTLvl(const Ring &ring, int level, const Poly &pIn, Poly &pOut) {
        lattigo_nNTTLvlRing(ring.getRawHandle(), level, pIn.getRawHandle(), pOut.getRawHandle());
    }
    

    void invMFormLvl(const RingQP &ringQP, int levelQ, int levelP, const PolyQP &pIn, PolyQP &pOut) {
        lattigo_invMFormLvlRingQP(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void mFormLvl(const RingQP &ringQP, int levelQ, int levelP, const PolyQP &pIn, PolyQP &pOut) {
       lattigo_mFormLvlRingQP(ringQP.getRawHandle(), levelQ, levelP, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void invMFormLvl(const Ring &ring, int level, const Poly &pIn, Poly &pOut) {
       lattigo_invMFormLvlRing(ring.getRawHandle(), level, pIn.getRawHandle(), pOut.getRawHandle());
    }

    void mFormLvl(const Ring &ring, int level, const Poly &pIn, Poly &pOut) {
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

    uint64_t N(const Ring &ring) { 
        return lattigo_N(ring.getRawHandle()); 
    }

    vector<uint64_t> permuteNTTIndex(const Ring &ring, uint64_t galEl) {
        vector<uint64_t> res(N(ring));
        lattigo_permuteNTTIndex(ring.getRawHandle(), galEl, res.data());
        return res;
    }

    void permuteNTTWithIndexLvl(const Ring &ring, uint64_t level, const Poly &polyIn, const vector<uint64_t> &index, Poly &polyOut) {
        lattigo_permuteNTTWithIndexLvl(ring.getRawHandle(), level, polyIn.getRawHandle(), index.data(), polyOut.getRawHandle());
    }

    int log2OfInnerSum(int level, const Ring &ring, const Poly &poly){
        return lattigo_log2OfInnerSum(level, ring.getRawHandle(), poly.getRawHandle());
    }

    void mulCoeffsMontgomeryAndAddLvl(const RingQP &ringQP, int levelQ, int levelP, const PolyQP &p1, const PolyQP &p2, const PolyQP &p3) {
        lattigo_MulCoeffsMontgomeryAndAddLvl(ringQP.getRawHandle(),levelQ, levelP, p1.getRawHandle(),p2.getRawHandle(),p3.getRawHandle());
    }

    void mulCoeffsMontgomeryAndAddLvl(const Ring &ring, int level, const Poly &p1, const Poly &p2, const Poly &p3) {
        lattigo_MulCoeffsMontgomeryAndAddLvlRing(ring.getRawHandle(),level, p1.getRawHandle(),p2.getRawHandle(),p3.getRawHandle());
    }

    int equals(const Poly &p1, const Poly &p2){
        return lattigo_equals(p1.getRawHandle(), p2.getRawHandle());
    }

    void print(const Poly &p){
        lattigo_printPoly(p.getRawHandle());
    }

} // namespace latticpp