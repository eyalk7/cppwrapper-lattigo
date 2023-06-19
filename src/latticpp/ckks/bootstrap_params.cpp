// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#include "bootstrap_params.h"

using namespace std;

namespace latticpp {

    BootstrappingParameters getBootstrappingParams(const NamedBootstrappingParams paramId, bool sparseParameters) {
        return BootstrappingParameters(lattigo_getBootstrappingParams(paramId, sparseParameters));
    }

    Parameters genParams(const NamedBootstrappingParams paramId, bool sparseParameters) {
        return Parameters(lattigo_params(paramId, sparseParameters));
    }

    uint64_t ephemeralSecretWeight(const BootstrappingParameters &bootParams) {
        return lattigo_ephemeralSecretWeight(bootParams.getRawHandle());
    }

    // int bootstrapDepth(const BootstrappingParameters &bootParams) {
    //     return lattigo_bootstrap_depth(bootParams.getRawHandle());
    // }
}  // namespace latticpp
