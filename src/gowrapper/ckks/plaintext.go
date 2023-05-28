// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

package ckks

import "C"

import (
	"lattigo-cpp/marshal"

	"github.com/tuneinsight/lattigo/v4/rlwe"
)

// https://github.com/golang/go/issues/35715#issuecomment-791039692
type Handle7 = uint64

func getStoredPlaintext(ptHandle Handle7) *rlwe.Plaintext {
	ref := marshal.CrossLangObjMap.Get(ptHandle)
	return (*rlwe.Plaintext)(ref.Ptr)
}
