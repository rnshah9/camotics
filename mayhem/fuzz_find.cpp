#include <stdint.h>
#include <stdio.h>
#include "Codes.h"
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);

    char ch = provider.ConsumeBytesAsString(1).c_str()[0];
    double d1 = provider.ConsumeFloatingPoint<double>();
    double d2 = provider.ConsumeFloatingPoint<double>();

    GCode::Codes::find(ch, d1, d2);

    return 0;
}