// SPDX-License-Identifier: Apache-2.0

#include "utils.h"

using namespace std;

namespace latticpp {

PRNG newPRNG() { return PRNG(lattigo_newPRNG()); }

} // namespace latticpp
