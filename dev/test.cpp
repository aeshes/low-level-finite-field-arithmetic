#include <iostream>
#include <cassert>
#include <array>

#include "field/field.h"

void test_zero_eq()
{
    auto a = field::zero();
    auto b = field::FieldElement({0, 0, 0, 0, 0});
    assert(a == b);
}

void test_reduce()
{
    std::array<uint8_t, 5> arr{59, 38, 59, 97, 23};
    auto reduced = field::reduce(arr);
    auto expected = field::FieldElement({59, 38, 59, 33, 24});
    assert(reduced == expected);
}

int main()
{
    test_zero_eq();
    test_reduce();
}