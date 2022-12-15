// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "cgo/dkeygen.h"
#include "latticpp/marshal/gohandle.h"
#include <vector>

namespace latticpp {

CKGProtocol newCKGProtocol(const Parameters &params);
RKGProtocol newRKGProtocol(const Parameters &params);
RTGProtocol newRTGProtocol(const Parameters &params);

} // namespace latticpp
