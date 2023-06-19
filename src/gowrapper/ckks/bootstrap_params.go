// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

package ckks

import "C"

import (
	"errors"
	"lattigo-cpp/marshal"
	"unsafe"

	"github.com/tuneinsight/lattigo/v4/ckks"
	"github.com/tuneinsight/lattigo/v4/ckks/bootstrapping"
)

// https://github.com/golang/go/issues/35715#issuecomment-791039692
type Handle11 = uint64

func getStoredBootstrappingParameters(bootParamHandle Handle11) *bootstrapping.Parameters {
	ref := marshal.CrossLangObjMap.Get(bootParamHandle)
	return (*bootstrapping.Parameters)(ref.Ptr)
}

//export lattigo_getBootstrappingParams
func lattigo_getBootstrappingParams(bootParamEnum uint8, sparseParameters bool) Handle11 {
	defaultParameters := bootstrapping.DefaultParametersDense
	if sparseParameters {
		defaultParameters = bootstrapping.DefaultParametersSparse
	}
	if int(bootParamEnum) >= len(defaultParameters) {
		panic(errors.New("bootstrapping parameter enum index out of bounds"))
	}

	paramsSet := defaultParameters[bootParamEnum]
	return marshal.CrossLangObjMap.Add(unsafe.Pointer(&paramsSet.BootstrappingParams))
}

//export lattigo_ephemeralSecretWeight
func lattigo_ephemeralSecretWeight(bootParamHandle Handle11) uint64 {
	var bootParams *bootstrapping.Parameters
	bootParams = getStoredBootstrappingParameters(bootParamHandle)
	return uint64(bootParams.EphemeralSecretWeight)
}

// // export lattigo_bootstrap_depth
// func lattigo_bootstrap_depth(bootParamHandle Handle11) uint64 {
// 	var bootParams *ckks.BootstrappingParameters
// 	bootParams = getStoredBootstrappingParameters(bootParamHandle)
// 	// len(bootParams.ResidualModuli) is the number of moduli available
// 	// post-bootstrapping, which is one more than the ciphertext level
// 	// after bootstrapping. Thus the difference, plus one, is the depth of
// 	// the bootstrapping circuit. For example, if the highest ciphertext
// 	// level is 10 and the post-bootstrapping *level* is 5, then the
// 	// length of the residual moduli vector is 6, so the depth of the bootstrapping
// 	// circuit is 10 - 6 + 1 = 5.
// 	return uint64(bootParams.MaxLevel() - len(bootParams.ResidualModuli) + 1)
// }

//export lattigo_params
func lattigo_params(bootParamEnum uint8, sparseParameters bool) Handle11 {
	defaultParameters := bootstrapping.DefaultParametersDense
	if sparseParameters {
		defaultParameters = bootstrapping.DefaultParametersSparse
	}
	if int(bootParamEnum) >= len(defaultParameters) {
		panic(errors.New("bootstrapping parameter enum index out of bounds"))
	}

	paramsSet := defaultParameters[bootParamEnum]
	var params ckks.Parameters
	var err error
	params, err = ckks.NewParametersFromLiteral(paramsSet.SchemeParams)
	if err != nil {
		panic(err)
	}

	return marshal.CrossLangObjMap.Add(unsafe.Pointer(&params))
}
