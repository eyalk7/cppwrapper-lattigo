// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "cgo/ciphertext.h"
#include "latticpp/marshal/gohandle.h"

namespace latticpp {

uint64_t level(const Ciphertext &ct);

double scale(const Ciphertext &ct);

int degree(const Ciphertext &ct);

Ciphertext copyNew(const Ciphertext &ct);

Ciphertext newCiphertext(const Parameters &params, uint64_t degree,
                         uint64_t level, double scale);
} // namespace latticpp
