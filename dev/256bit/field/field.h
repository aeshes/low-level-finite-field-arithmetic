#ifndef FIELD_H
#define FIELD_H

#include <cstdint>
#include <array>

/*
    Finite field GF(p)
    p = 2^255 - 19
    using 2^255 = 19 mod p
*/

namespace field
{

    class FieldElement
    {
        std::array<uint64_t, 5> chunks;

    public:
        FieldElement(std::array<uint64_t, 5> a);

        friend bool operator==(const FieldElement&, const FieldElement&);
        friend FieldElement operator+(const FieldElement&, const FieldElement&);
    };

    bool operator==(const FieldElement& lhs, const FieldElement& rhs);
    FieldElement operator+(const FieldElement& lhs, const FieldElement& rhs);

    FieldElement zero();
    FieldElement one();

    FieldElement reduce(std::array<uint64_t, 5>& a);
}

#endif