// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "cgo/keygen.h"
#include "latticpp/marshal/gohandle.h"
#include <vector>

namespace latticpp {

struct KeyPairHandle {
  SecretKey sk;
  PublicKey pk;
};

KeyGenerator newKeyGenerator(const Parameters &params);

RotationKey getRotationKey(const Parameters &params, const RotationKeys &rtks,
                           int rotationStep);

RotationKey copyNewRotationKey(const RotationKey &rotKey);

uint64_t numOfDecomp(const RotationKey &rtk);

uint64_t galoisElementForColumnRotationBy(const Parameters &params,
                                          uint64_t rotationStep);

uint64_t rotationKeyIsCorrect(const RotationKey &rtk, uint64_t galEl,
                              SecretKey sk, const Parameters &params,
                              uint64_t log2Bound);

SecretKey newSecretKey(const Parameters &params);

SecretKey copyNewSecretKey(const SecretKey &sk);

PolyQP getPolyQP(const SecretKey &sk);

PublicKey newPublicKey(const Parameters &params);

RelinearizationKey newRelinearizationKey(const Parameters &params);

RotationKeys newRotationKeys(const Parameters &params,
                             std::vector<uint64_t> galoisElements);

SecretKey genSecretKey(const KeyGenerator &keygen);

PublicKey genPublicKey(const KeyGenerator &keygen, const SecretKey &sk);

KeyPairHandle genKeyPair(const KeyGenerator &keygen);

KeyPairHandle genKeyPairSparse(const KeyGenerator &keygen, uint64_t hw);

RelinearizationKey genRelinKey(const KeyGenerator &keygen, const SecretKey &sk);

RotationKeys genRotationKeysForRotations(const KeyGenerator &keygen,
                                         const SecretKey &sk,
                                         std::vector<int> shifts);

EvaluationKey makeEvaluationKey(const RelinearizationKey &relinKey,
                                const RotationKeys &rotKeys);

EvaluationKey makeEmptyEvaluationKey();

void setRelinKeyForEvaluationKey(const EvaluationKey &evalKey,
                                 const RelinearizationKey &relinKey);

void setRotKeysForEvaluationKey(const EvaluationKey &evalKey,
                                const RotationKeys &rotKeys);

// BootstrappingKey genBootstrappingKey(const KeyGenerator &keygen, const
// Parameters &params, const BootstrappingParameters &bootParams, const
// SecretKey &sk, const RelinearizationKey &relinKey, const RotationKeys
// &rotKeys);

// BootstrappingKey makeBootstrappingKey(const RelinearizationKey &relinKey,
// const RotationKeys &rotKeys);

SwitchingKey getSwitchingKey(RotationKeys &rotKeys, uint64_t galoisElement);

} // namespace latticpp
