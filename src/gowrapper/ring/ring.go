// SPDX-License-Identifier: Apache-2.0

package ring

/*
#include <stdint.h>
*/
import "C"

import (
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

func getStoredPolyQP(polyQpHandle Handle14) *ringqp.Poly {
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

//export lattigo_newPoly
func lattigo_newPoly(ringHandle Handle14) Handle14 {
	r := getStoredRing(ringHandle)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(r.NewPoly()))
}

//export lattigo_ringAdd
func lattigo_ringAdd(ringHandle, poly1Handle, poly2Handle, poly3Handle Handle14) {
	r := getStoredRing(ringHandle)
	p1 := GetStoredPoly(poly1Handle)
	p2 := GetStoredPoly(poly2Handle)
	p3 := GetStoredPoly(poly3Handle)
	r.Add(p1, p2, p3)
}

//export lattigo_polyCopy
func lattigo_polyCopy(polyTargetHandle, polySrcHandle Handle14) {
	pTarget := GetStoredPoly(polyTargetHandle)
	pSrc := GetStoredPoly(polySrcHandle)
	pTarget.Copy(pSrc)
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

//export lattigo_invNTTLvl
func lattigo_invNTTLvl(ringQPHandle Handle14, levelQ, levelP int, pInHandle, pOutHandle Handle14) {
	ringQP := getStoredRingQP(ringQPHandle)
	pIn := getStoredPolyQP(pInHandle)
	pOut := getStoredPolyQP(pOutHandle)
	ringQP.InvNTTLvl(levelQ, levelP, *pIn, *pOut)
}

//export lattigo_nTTLvl
func lattigo_nTTLvl(ringQPHandle Handle14, levelQ, levelP int, pInHandle, pOutHandle Handle14) {
	ringQP := getStoredRingQP(ringQPHandle)
	pIn := getStoredPolyQP(pInHandle)
	pOut := getStoredPolyQP(pOutHandle)
	ringQP.NTTLvl(levelQ, levelP, *pIn, *pOut)
}

//export lattigo_invMFormLvl
func lattigo_invMFormLvl(ringQPHandle Handle14, levelQ, levelP int, pInHandle, pOutHandle Handle14) {
	ringQP := getStoredRingQP(ringQPHandle)
	pIn := getStoredPolyQP(pInHandle)
	pOut := getStoredPolyQP(pOutHandle)
	ringQP.InvMFormLvl(levelQ, levelP, *pIn, *pOut)
}

//export lattigo_mFormLvl
func lattigo_mFormLvl(ringQPHandle Handle14, levelQ, levelP int, pInHandle, pOutHandle Handle14) {
	ringQP := getStoredRingQP(ringQPHandle)
	pIn := getStoredPolyQP(pInHandle)
	pOut := getStoredPolyQP(pOutHandle)
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
	polyQP := getStoredPolyQP(polyQPHandle)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(polyQP.Q))
}

//export lattigo_polyP
func lattigo_polyP(polyQPHandle Handle14) Handle14 {
	polyQP := getStoredPolyQP(polyQPHandle)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(polyQP.P))
}

//export lattigo_copyLvl
func lattigo_copyLvl(level uint64, sourcePolyHandle, targetPolyHandle Handle14) {
	sourcePoly := getStoredPoly(sourcePolyHandle)
	targetPoly := getStoredPoly(targetPolyHandle)
	ring.CopyLvl(int(level), sourcePoly, targetPoly)
}

//export lattigo_copyPolySingleLevel
func lattigo_copyPolySingleLevel(sourcePolyHandle Handle14, sourceIndex uint64, targetPolyHandle Handle14, targetIndex uint64) {
	src := getStoredPoly(sourcePolyHandle)
	tar := getStoredPoly(targetPolyHandle)
	srcIdx := int(sourceIndex)
	tarIdx := int(targetIndex)
	copy(tar.Buff[tar.N()*tarIdx:tar.N()*(tarIdx+1)], src.Buff[src.N()*srcIdx:src.N()*(srcIdx+1)])
}

//export lattigo_polyDegree
func lattigo_polyDegree(polyHandle Handle14) uint64 {
	poly := getStoredPoly(polyHandle)
	return uint64(poly.N())
}
