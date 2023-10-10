#include "coding_challenge.h"
#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>
#include <stdio.h>

FUZZ_TEST_SETUP() {}

FUZZ_TEST(const uint8_t *data, size_t size) {

  // As the function we want to fuzz expect two integers and one string we
  // have to convert/cast the given input data into the expected variables/data
  // types
  FuzzedDataProvider fuzzed_data(data, size);
  int a = fuzzed_data.ConsumeIntegralInRange<int>(1, 100);
  char buffer[a];
  
  strncpy(buffer, fuzzed_data.ConsumeBytesAsString(a-1).c_str(), a);

  strange_parse(buffer);
}
