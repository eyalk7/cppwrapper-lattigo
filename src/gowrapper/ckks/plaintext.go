// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

package ckks

import "C"

import (
	"lattigo-cpp/marshal"
	"lattigo-cpp/ring"
	"unsafe"

	"github.com/tuneinsight/lattigo/v4/ckks"
	"github.com/tuneinsight/lattigo/v4/rlwe"
)

// https://github.com/golang/go/issues/35715#issuecomment-791039692
type Handle7 = uint64

func getStoredPlaintext(ptHandle Handle7) *rlwe.Plaintext {
	ref := marshal.CrossLangObjMap.Get(ptHandle)
	return (*rlwe.Plaintext)(ref.Ptr)
}

//export lattigo_newPlaintext
func lattigo_newPlaintext(paramsHandle, polyHandle Handle7, level uint64) Handle7 {
	params := getStoredParameters(paramsHandle)
	poly := ring.GetStoredPoly(polyHandle)
	plaintext := ckks.NewPlaintext(*params, int(level))
	plaintext.Value = poly
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(plaintext))
}

//export lattigo_getPlaintextPoly
func lattigo_getPlaintextPoly(plaintextHandler Handle7) Handle7 {
	plaintext := getStoredPlaintext(plaintextHandler)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(plaintext.Value))
}
