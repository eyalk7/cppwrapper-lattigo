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

    uint64_t ephemeralSecretWeight(const BootstrappingParameters &bootParams);
}  // namespace latticpp
