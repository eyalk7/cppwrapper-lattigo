// SPDX-License-Identifier: Apache-2.0

package dckks

// cgo will automatically generate a struct for functions which return multiple values,
// but the auto-generated struct with generated names loses its semantic value. We opt
// to define our own struct here.

import "C"

import (
	"lattigo-cpp/ckks"
	"lattigo-cpp/marshal"
	"unsafe"

	"github.com/ldsec/lattigo/v2/dckks"
)

// https://github.com/golang/go/issues/35715#issuecomment-791039692
type Handle13 = uint64

func getStoredCKGProtocol(keygenHandle Handle13) *dckks.CKGProtocol {
	ref := marshal.CrossLangObjMap.Get(keygenHandle)
	return (*dckks.CKGProtocol)(ref.Ptr)
}

func getStoredRKGProtocol(keygenHandle Handle13) *dckks.RKGProtocol {
	ref := marshal.CrossLangObjMap.Get(keygenHandle)
	return (*dckks.RKGProtocol)(ref.Ptr)
}

func getStoredRTGProtocol(keygenHandle Handle13) *dckks.RTGProtocol {
	ref := marshal.CrossLangObjMap.Get(keygenHandle)
	return (*dckks.RTGProtocol)(ref.Ptr)
}

//export lattigo_newCKGProtocol
func lattigo_newCKGProtocol(paramHandle Handle13) Handle13 {
	paramPtr := ckks.GetStoredParameters(paramHandle)
	var protocol *dckks.CKGProtocol
	protocol = dckks.NewCKGProtocol(*paramPtr)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(protocol))
}

//export lattigo_newRKGProtocol
func lattigo_newRKGProtocol(paramHandle Handle13) Handle13 {
	paramPtr := ckks.GetStoredParameters(paramHandle)
	var protocol *dckks.RKGProtocol
	protocol = dckks.NewRKGProtocol(*paramPtr)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(protocol))
}

//export lattigo_newRotKGProtocol
func lattigo_newRotKGProtocol(paramHandle Handle13) Handle13 {
	paramPtr := ckks.GetStoredParameters(paramHandle)
	var protocol *dckks.RTGProtocol
	protocol = dckks.NewRotKGProtocol(*paramPtr)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(protocol))
}
