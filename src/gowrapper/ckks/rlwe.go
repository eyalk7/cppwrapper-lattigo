package ckks

import (
	"lattigo-cpp/marshal"

	"github.com/tuneinsight/lattigo/v4/rlwe"
)

type Handle16 = uint64

func getStoredScale(scaleHandle Handle16) *rlwe.Scale {
	ref := marshal.CrossLangObjMap.Get(scaleHandle)
	return (*rlwe.Scale)(ref.Ptr)
}
