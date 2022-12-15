// SPDX-License-Identifier: Apache-2.0

package ring

// cgo will automatically generate a struct for functions which return multiple values,
// but the auto-generated struct with generated names loses its semantic value. We opt
// to define our own struct here.

/*
#include <stdint.h>
*/
import "C"

import (
	"lattigo-cpp/marshal"
	"unsafe"

	"github.com/ldsec/lattigo/v2/ring"
)

// https://github.com/golang/go/issues/35715#issuecomment-791039692
type Handle14 = uint64

func getStoredRing(keygenHandle Handle14) *ring.Ring {
	ref := marshal.CrossLangObjMap.Get(keygenHandle)
	return (*ring.Ring)(ref.Ptr)
}

//export lattigo_newRing
func lattigo_newRing(n int, moduli *C.uint64_t, muduliLen uint64) Handle14 {

	moduliTmp := make([]uint64, muduliLen)
	size := unsafe.Sizeof(uint64(0))
	basePtrIn := uintptr(unsafe.Pointer(&moduli))
	for i := range moduliTmp {
		moduliTmp[i] = *(*uint64)(unsafe.Pointer(basePtrIn + size*uintptr(i)))
	}

	r, _ := ring.NewRing(n, moduliTmp)
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(r))
}
