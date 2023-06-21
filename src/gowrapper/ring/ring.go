// SPDX-License-Identifier: Apache-2.0

package ring

/*
#include <stdint.h>
typedef const uint64_t constULong;
typedef const double constDouble;
*/
import "C"

import (
	"fmt"
	"lattigo-cpp/marshal"
	"lattigo-cpp/utils"
	"unsafe"

	"github.com/tuneinsight/lattigo/v4/ring"
	"github.com/tuneinsight/lattigo/v4/rlwe/ringqp"
)

// https://github.com/golang/go/issues/35715#issuecomment-791039692
type Handle14 = uint64

func getStoredRing(ringHandle Handle14) *ring.Ring {
	ref := marshal.CrossLangObjMap.Get(ringHandle)
	return (*ring.Ring)(ref.Ptr)
}

func getStoredRingQP(ringHandle Handle14) *ringqp.Ring {
	ref := marshal.CrossLangObjMap.Get(ringHandle)
	return (*ringqp.Ring)(ref.Ptr)
}

func GetStoredPoly(polyHandle Handle14) *ring.Poly {
	ref := marshal.CrossLangObjMap.Get(polyHandle)
	return (*ring.Poly)(ref.Ptr)
}

func getStoredUniformSampler(samplerHandle Handle14) *ring.UniformSampler {
	ref := marshal.CrossLangObjMap.Get(samplerHandle)
	return (*ring.UniformSampler)(ref.Ptr)
}

func GetStoredPolyQP(polyQpHandle Handle14) *ringqp.Poly {
	ref := marshal.CrossLangObjMap.Get(polyQpHandle)
	return (*ringqp.Poly)(ref.Ptr)
}

func getStoredPoly(polyHandle Handle14) *ring.Poly {
	ref := marshal.CrossLangObjMap.Get(polyHandle)
	return (*ring.Poly)(ref.Ptr)
}

func getStoredBasisExtender(basisExtenderHandle Handle14) *ring.BasisExtender {
	ref := marshal.CrossLangObjMap.Get(basisExtenderHandle)
	return (*ring.BasisExtender)(ref.Ptr)
}

//export lattigo_newRing
func lattigo_newRing(n uint64, moduli *C.uint64_t, moduliLen uint64) Handle14 {
	moduliTmp := make([]uint64, moduliLen)
	size := unsafe.Sizeof(uint64(0))
	basePtrIn := uintptr(unsafe.Pointer(&moduli))
	for i := range moduliTmp {
		moduliTmp[i] = *(*uint64)(unsafe.Pointer(basePtrIn + size*uintptr(i)))
	}

	r, err := ring.NewRing(int(n), moduliTmp)

	if err != nil {
		panic(err)
	}
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(r))
}

//export lattigo_newPolyQP
func lattigo_newPolyQP(ringHandle Handle14) Handle14 {
	r := getStoredRingQP(ringHandle)
	poly := r.NewPoly()
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(&poly))
}

//export lattigo_ringQPAddLvl
func lattigo_ringQPAddLvl(ringHandle Handle14, levelQ, levelP uint64, poly1Handle, poly2Handle, poly3Handle Handle14) {
	r := getStoredRingQP(ringHandle)
	p1 := GetStoredPolyQP(poly1Handle)
	p2 := GetStoredPolyQP(poly2Handle)
	p3 := GetStoredPolyQP(poly3Handle)
	r.AddLvl(int(levelQ), int(levelP), *p1, *p2, *p3)
}

//export lattigo_polyQPCopy
func lattigo_polyQPCopy(polyTargetHandle, polySrcHandle Handle14) {
	pTarget := GetStoredPolyQP(polyTargetHandle)
	pSrc := GetStoredPolyQP(polySrcHandle)
	pTarget.Copy(*pSrc)
}

//export lattigo_newUniformSampler
func lattigo_newUniformSampler(prngHandle, baseRingHandle Handle14) Handle14 {
	prng := utils.GetStoredKeyedPRNG(prngHandle)
	r := getStoredRing(baseRingHandle)
	sampler := ring.NewUniformSampler(prng, r)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(sampler))
}

//export lattigo_readNewFromSampler
func lattigo_readNewFromSampler(samplerHandle Handle14) Handle14 {
	sampler := getStoredUniformSampler(samplerHandle)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(sampler.ReadNew()))
}

//export lattigo_newBasisExtender
func lattigo_newBasisExtender(ringQHandle, ringPHandle Handle14) Handle14 {
	ringQ := getStoredRing(ringQHandle)
	ringP := getStoredRing(ringPHandle)
	basisExtender := ring.NewBasisExtender(ringQ, ringP)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(basisExtender))

}

//export lattigo_modUpQtoP
func lattigo_modUpQtoP(basisExtenderHandle Handle14, levelQ, levelP int, polQHandle, polPHandle Handle14) {
	basisExtender := getStoredBasisExtender(basisExtenderHandle)
	polQ := getStoredPoly(polQHandle)
	polP := getStoredPoly(polPHandle)
	basisExtender.ModUpQtoP(levelQ, levelP, polQ, polP)
}

//export lattigo_invNTTLvlRingQP
func lattigo_invNTTLvlRingQP(ringQPHandle Handle14, levelQ, levelP int, pInHandle, pOutHandle Handle14) {
	ringQP := getStoredRingQP(ringQPHandle)
	pIn := GetStoredPolyQP(pInHandle)
	pOut := GetStoredPolyQP(pOutHandle)
	ringQP.InvNTTLvl(levelQ, levelP, *pIn, *pOut)
}

//export lattigo_nTTLvlRingQP
func lattigo_nTTLvlRingQP(ringQPHandle Handle14, levelQ, levelP int, pInHandle, pOutHandle Handle14) {
	ringQP := getStoredRingQP(ringQPHandle)
	pIn := GetStoredPolyQP(pInHandle)
	pOut := GetStoredPolyQP(pOutHandle)
	ringQP.NTTLvl(levelQ, levelP, *pIn, *pOut)
}

//export lattigo_invNTTLvlRing
func lattigo_invNTTLvlRing(ringHandle Handle14, level int, pInHandle, pOutHandle Handle14) {
	ring := getStoredRing(ringHandle)
	pIn := getStoredPoly(pInHandle)
	pOut := getStoredPoly(pOutHandle)
	ring.InvNTTLvl(level, pIn, pOut)
}

//export lattigo_nNTTLvlRing
func lattigo_nNTTLvlRing(ringHandle Handle14, level int, pInHandle, pOutHandle Handle14) {
	ring := getStoredRing(ringHandle)
	pIn := getStoredPoly(pInHandle)
	pOut := getStoredPoly(pOutHandle)
	ring.NTTLvl(level, pIn, pOut)
}

//export lattigo_invMFormLvlRingQP
func lattigo_invMFormLvlRingQP(ringQPHandle Handle14, levelQ, levelP int, pInHandle, pOutHandle Handle14) {
	ringQP := getStoredRingQP(ringQPHandle)
	pIn := GetStoredPolyQP(pInHandle)
	pOut := GetStoredPolyQP(pOutHandle)
	ringQP.InvMFormLvl(levelQ, levelP, *pIn, *pOut)
}

//export lattigo_mFormLvlRingQP
func lattigo_mFormLvlRingQP(ringQPHandle Handle14, levelQ, levelP int, pInHandle, pOutHandle Handle14) {
	ringQP := getStoredRingQP(ringQPHandle)
	pIn := GetStoredPolyQP(pInHandle)
	pOut := GetStoredPolyQP(pOutHandle)
	ringQP.MFormLvl(levelQ, levelP, *pIn, *pOut)
}

//export lattigo_invMFormLvlRing
func lattigo_invMFormLvlRing(ringHandle Handle14, level int, pInHandle, pOutHandle Handle14) {
	ring := getStoredRing(ringHandle)
	pIn := getStoredPoly(pInHandle)
	pOut := getStoredPoly(pOutHandle)
	ring.InvMFormLvl(level, pIn, pOut)
}

//export lattigo_mFormLvlRing
func lattigo_mFormLvlRing(ringHandle Handle14, level int, pInHandle, pOutHandle Handle14) {
	ring := getStoredRing(ringHandle)
	pIn := getStoredPoly(pInHandle)
	pOut := getStoredPoly(pOutHandle)
	ring.MFormLvl(level, pIn, pOut)
}

//export lattigo_polyQ
func lattigo_polyQ(polyQPHandle Handle14) Handle14 {
	polyQP := GetStoredPolyQP(polyQPHandle)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(polyQP.Q))
}

//export lattigo_polyP
func lattigo_polyP(polyQPHandle Handle14) Handle14 {
	polyQP := GetStoredPolyQP(polyQPHandle)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(polyQP.P))
}

//export lattigo_copyLvl
func lattigo_copyLvl(level uint64, sourcePolyHandle, targetPolyHandle Handle14) {
	sourcePoly := getStoredPoly(sourcePolyHandle)
	targetPoly := getStoredPoly(targetPolyHandle)
	ring.CopyLvl(int(level), sourcePoly, targetPoly)
}

//export lattigo_copyPolyAtLevel
func lattigo_copyPolyAtLevel(dstPolyHandle Handle14, dstIndex uint64, srcPolyHandle Handle14, srcIndex uint64) {
	src := getStoredPoly(srcPolyHandle)
	dst := getStoredPoly(dstPolyHandle)
	srcIdx := int(srcIndex)
	dstIdx := int(dstIndex)
	copy(dst.Coeffs[dstIdx], src.Coeffs[srcIdx])
}

//export lattigo_newPoly
func lattigo_newPoly(ringHandle Handle14) Handle14 {
	ring := getStoredRing(ringHandle)
	poly := ring.NewPoly()
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(poly))
}

//export lattigo_copyPoly
func lattigo_copyPoly(polyTargetHandle, polySrcHandle Handle14) {
	pTarget := GetStoredPoly(polyTargetHandle)
	pSrc := GetStoredPoly(polySrcHandle)
	pTarget.Copy(pSrc)
}

//export lattigo_polyDegree
func lattigo_polyDegree(polyHandle Handle14) uint64 {
	poly := getStoredPoly(polyHandle)
	return uint64(poly.N())
}

//export lattigo_N
func lattigo_N(ringHandle Handle14) uint64 {
	ring := getStoredRing(ringHandle)
	return uint64(ring.N)
}

//export lattigo_permuteNTTIndex
func lattigo_permuteNTTIndex(ringHandle Handle14, galEl uint64, outValues *C.constULong) {
	ring := getStoredRing(ringHandle)
	res := ring.PermuteNTTIndex(galEl)
	size := unsafe.Sizeof(uint64(0))
	basePtr := uintptr(unsafe.Pointer(outValues))
	for i := range res {
		*(*uint64)(unsafe.Pointer(basePtr + size*uintptr(i))) = res[i]
	}
}

//export lattigo_permuteNTTWithIndexLvl
func lattigo_permuteNTTWithIndexLvl(ringHandle Handle14, level uint64, polyInHandle Handle14, index *C.constULong, polyOutHandle Handle14) {
	ring := getStoredRing(ringHandle)
	polyIn := getStoredPoly(polyInHandle)
	polyOut := getStoredPoly(polyOutHandle)
	Index := make([]uint64, ring.N)
	indexPtr := uintptr(unsafe.Pointer(index))
	size := unsafe.Sizeof(uint64(0))
	for i := range Index {
		Index[i] = *(*uint64)(unsafe.Pointer(indexPtr + size*uintptr(i)))
	}
	ring.PermuteNTTWithIndexLvl(int(level), polyIn, Index, polyOut)
}

//export lattigo_log2OfInnerSum
func lattigo_log2OfInnerSum(levelQ int, ringQHandle, polyHandle Handle14) int {
	ringQ := getStoredRing(ringQHandle)
	poly := getStoredPoly(polyHandle)
	return ringQ.Log2OfInnerSum(levelQ, poly)
}

//export lattigo_MulCoeffsMontgomeryAndAddLvl
func lattigo_MulCoeffsMontgomeryAndAddLvl(ringQPHandle Handle14, levelQ, levelP int, p1Handle, p2Handle, p3Handle Handle14) {
	p1 := GetStoredPolyQP(p1Handle)
	p2 := GetStoredPolyQP(p2Handle)
	p3 := GetStoredPolyQP(p3Handle)
	ringQP := getStoredRingQP(ringQPHandle)
	ringQP.RingQ.MulCoeffsMontgomeryAndAddLvl(levelQ, p1.Q, p2.Q, p3.Q)
	ringQP.RingP.MulCoeffsMontgomeryAndAddLvl(levelP, p1.P, p2.P, p3.P)
}

//export lattigo_MulCoeffsMontgomeryAndAddLvlRing
func lattigo_MulCoeffsMontgomeryAndAddLvlRing(ringHandle Handle14, level int, p1Handle, p2Handle, p3Handle Handle14) {
	p1 := getStoredPoly(p1Handle)
	p2 := getStoredPoly(p2Handle)
	p3 := getStoredPoly(p3Handle)
	ring := getStoredRing(ringHandle)
	ring.MulCoeffsMontgomeryAndAddLvl(level, p1, p2, p3)
}

//export lattigo_equals
func lattigo_equals(p1Handle, p2Handle Handle14) int {
	p1 := getStoredPoly(p1Handle)
	p2 := getStoredPoly(p2Handle)
	if p1.Equals(p2) {
		return 1
	} else {
		return 0
	}
}

//export lattigo_printPoly
func lattigo_printPoly(pHandle Handle14) {
	p := getStoredPoly(pHandle)
	for level := range p.Coeffs {
		fmt.Println("level:", level, " = ", p.Coeffs[level][0], p.Coeffs[level][1], p.Coeffs[level][2], p.Coeffs[level][3], p.Coeffs[level][4])
	}
}
