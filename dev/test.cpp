#include <iostream>
#include <cassert>

#include "field/field.h"

void test_zero_eq()
{
    auto a = field::zero();
    auto b = field::FieldElement({0, 0, 0, 0, 0});
    assert(a == b);
}

int main()
{
    test_zero_eq();
}