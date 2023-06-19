// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "latticpp/marshal/gohandle.h"
#include "cgo/bootstrap_params.h"

namespace latticpp {

    // These correspond to the default bootstrapping parameters provided in Lattigo
    enum NamedBootstrappingParams {
        BootstrapParams_Set1,
        BootstrapParams_Set2,
        BootstrapParams_Set3,
        BootstrapParams_Set4
    };

    BootstrappingParameters getBootstrappingParams(const NamedBootstrappingParams paramId, bool sparseParameters = false);

    Parameters genParams(const NamedBootstrappingParams paramId, bool sparseParameters = false);

    // Get the Hamming weight of the ephemeral secret. If 0, no ephemeral secret is used during the bootstrapping.
    uint64_t ephemeralSecretWeight(const BootstrappingParameters &bootParams);

    // // The multiplicative depth of the bootstrapping circuit
    // int bootstrapDepth(const BootstrappingParameters &bootParams);
}  // namespace latticpp
