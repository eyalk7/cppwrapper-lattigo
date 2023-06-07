// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

package ckks

import "C"

import (
	"lattigo-cpp/marshal"
	"unsafe"

	"github.com/tuneinsight/lattigo/v4/ckks"
	"github.com/tuneinsight/lattigo/v4/rlwe"
)

// https://github.com/golang/go/issues/35715#issuecomment-791039692
type Handle8 = uint64

func getStoredCiphertext(ctHandle Handle8) *rlwe.Ciphertext {
	ref := marshal.CrossLangObjMap.Get(ctHandle)
	return (*rlwe.Ciphertext)(ref.Ptr)
}

func getStoredCiphertextQP(ctHandle Handle8) *rlwe.CiphertextQP {
	ref := marshal.CrossLangObjMap.Get(ctHandle)
	return (*rlwe.CiphertextQP)(ref.Ptr)
}

func getStoredMetaData(metaDataHandle Handle8) *rlwe.MetaData {
	ref := marshal.CrossLangObjMap.Get(metaDataHandle)
	return (*rlwe.MetaData)(ref.Ptr)
}

//export lattigo_level
func lattigo_level(ctHandle Handle8) uint64 {
	var ctIn *rlwe.Ciphertext
	ctIn = getStoredCiphertext(ctHandle)
	return uint64(ctIn.Level())
}

//export lattigo_ciphertextScale
func lattigo_ciphertextScale(ctHandle Handle8) float64 {
	var ctIn *rlwe.Ciphertext
	ctIn = getStoredCiphertext(ctHandle)
	return ctIn.Scale.Float64()
}

//export lattigo_ciphertextDegree
func lattigo_ciphertextDegree(ctHandle Handle8) uint64 {
	ct := getStoredCiphertext(ctHandle)
	return uint64(ct.Degree())
}

//export lattigo_copyNew
func lattigo_copyNew(ctHandle Handle8) Handle8 {
	var ctIn *rlwe.Ciphertext
	ctIn = getStoredCiphertext(ctHandle)

	var ctClone *rlwe.Ciphertext
	ctClone = ctIn.CopyNew()
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(ctClone))
}

//export lattigo_newCiphertext
func lattigo_newCiphertext(paramsHandle Handle8, degree uint64, level uint64) Handle8 {
	var params *ckks.Parameters
	params = getStoredParameters(paramsHandle)

	var newCt *rlwe.Ciphertext
	newCt = ckks.NewCiphertext(*params, int(degree), int(level))
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(newCt))
}

//export lattigo_setCiphertextMetaData
func lattigo_setCiphertextMetaData(ctxHandle, metaDataHandle Handle8) {
	ctx := getStoredCiphertext(ctxHandle)
	metaData := getStoredMetaData(metaDataHandle)
	(*ctx).MetaData = *metaData
}

//export lattigo_setCiphertextQPMetaData
func lattigo_setCiphertextQPMetaData(ctxQPHandle, metaDataHandle Handle8) {
	ctxQP := getStoredCiphertextQP(ctxQPHandle)
	metaData := getStoredMetaData(metaDataHandle)
	(*ctxQP).MetaData = *metaData
}

//export lattigo_getCiphertextMetaData
func lattigo_getCiphertextMetaData(ctxHandle Handle8) Handle8 {
	ctx := getStoredCiphertext(ctxHandle)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(&ctx.MetaData))
}

//export lattigo_getCiphertextQPMetaData
func lattigo_getCiphertextQPMetaData(ctxHandle Handle8) Handle8 {
	ctxQP := getStoredCiphertextQP(ctxHandle)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(&ctxQP.MetaData))
}

//export lattigo_poly
func lattigo_poly(ctxHandle Handle8, i uint64) Handle8 {
	ctx := getStoredCiphertext(ctxHandle)
	if int(i) > ctx.Degree() {
		panic("index exceed ciphertext degree")
	}
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(ctx.Value[i]))
}
