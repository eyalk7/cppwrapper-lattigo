// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "cgo/ring.h"
#include "latticpp/marshal/gohandle.h"
#include <vector>

namespace latticpp {

Ring newRing(int n, std::vector<uint64_t> moduli);

} // namespace latticpp
