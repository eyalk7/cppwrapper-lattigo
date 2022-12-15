// SPDX-License-Identifier: Apache-2.0

package utils

// cgo will automatically generate a struct for functions which return multiple values,
// but the auto-generated struct with generated names loses its semantic value. We opt
// to define our own struct here.

import "C"

import (
	"lattigo-cpp/marshal"
	"unsafe"

	"github.com/ldsec/lattigo/v2/utils"
)

// https://github.com/golang/go/issues/35715#issuecomment-791039692
type Handle15 = uint64

func getStoredKeyedPRNG(keygenHandle Handle15) *utils.KeyedPRNG {
	ref := marshal.CrossLangObjMap.Get(keygenHandle)
	return (*utils.KeyedPRNG)(ref.Ptr)
}

//export lattigo_newPRNG
func lattigo_newPRNG() Handle15 {
	// prng is of type KeyedPRNG
	prng, _ := utils.NewPRNG()
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(prng))
}
