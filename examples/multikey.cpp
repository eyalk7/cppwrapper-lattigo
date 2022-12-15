// SPDX-License-Identifier: Apache-2.0

#include "latticpp/latticpp.h"

#include <cmath>
#include <iomanip>
#include <random>
#include <vector>

using namespace std;
using namespace latticpp;

struct TestContext {
  Parameters params;

  Ring ringQ;
  Ring ringQP;

  PRNG prng;

  Encoder encoder;
  Evaluator evaluator;

  Encryptor encryptorPk0;
  Decryptor decryptorSk0;
  Decryptor decryptorSk1;

  PublicKey pk0;
  PublicKey pk1;

  SecretKey sk0;
  SecretKey sk1;

  vector<SecretKey> sk0Shards;
  vector<SecretKey> sk1Shards;
};

Parameters genenerateParamsForTest() {
  BootstrappingParameters btpParams =
      getBootstrappingParams(BootstrapParams_Set5);
  Parameters params = genParams(btpParams);

  cout << "CKKS parameters: logN = " << logN(params)
       << ", logSlots = " << logSlots(params)
       << ", h = " << secretHammingWeight(btpParams)
       << ", logQP = " << logQP(params) << ", levels = " << qiCount(params)
       << ", scale = 2^" << log2(scale(params)) << ", sigma = " << sigma(params)
       << endl;

  return params;
}

void generateTestContextForTest(TestContext &res, const Parameters &params) {
  res.params = params;
  res.ringQ = ringQ(params);
  res.ringQP = ringQP(params);
}

int main() {
  Parameters params = genenerateParamsForTest();

  TestContext testContext;
  generateTestContextForTest(testContext, params);

  return 0;
}
