// SPDX-License-Identifier: Apache-2.0

#include "ring.h"

using namespace std;

namespace latticpp {

Ring newRing(int n, vector<uint64_t> moduli) {
  return Ring(lattigo_newRing(n, moduli.data(), moduli.size()));
}

} // namespace latticpp
