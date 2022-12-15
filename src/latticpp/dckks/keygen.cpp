// SPDX-License-Identifier: Apache-2.0

#include "keygen.h"

using namespace std;

namespace latticpp {

CKGProtocol newCKGProtocol(const Parameters &params) {
  return CKGProtocol(lattigo_newCKGProtocol(params.getRawHandle()));
}

RKGProtocol newRKGProtocol(const Parameters &params) {
  return RKGProtocol(lattigo_newRKGProtocol(params.getRawHandle()));
}

RTGProtocol newRTGProtocol(const Parameters &params) {
  return RTGProtocol(lattigo_newRotKGProtocol(params.getRawHandle()));
}

} // namespace latticpp
