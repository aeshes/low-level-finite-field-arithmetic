#include "field.h"

using field::FieldElement;

FieldElement::FieldElement(std::array<uint64_t, 5> a)
{
    chunks[0] = a[0];
    chunks[1] = a[1];
    chunks[2] = a[2];
    chunks[3] = a[3];
    chunks[4] = a[4];
}

namespace field
{
    bool operator==(const FieldElement& lhs, const FieldElement& rhs)
    {
        return lhs.chunks == rhs.chunks;
    }

    FieldElement operator+(const FieldElement& lhs, const FieldElement& rhs)
    {
        std::array<uint64_t, 5> r{0, 0, 0, 0, 0};
        for (int i = 0; i < 5; ++i)
        {
            r[i] = lhs.chunks[i] + rhs.chunks[i];
        }
    }

    FieldElement zero()
    {
        return FieldElement({0, 0, 0, 0, 0});
    }

    FieldElement one()
    {
        return FieldElement({1, 0, 0, 0, 0});
    }

    FieldElement reduce(std::array<uint64_t, 5>& limbs)
    {
        const uint64_t LOW_51_BIT_MASK = (static_cast<uint64_t>(1) << 51) - 1;

        uint64_t carry0 = limbs[0] >> 51;
        uint64_t carry1 = limbs[1] >> 51;
        uint64_t carry2 = limbs[2] >> 51;
        uint64_t carry3 = limbs[3] >> 51;
        uint64_t carry4 = limbs[4] >> 51;

        limbs[0] &= LOW_51_BIT_MASK;
        limbs[1] &= LOW_51_BIT_MASK;
        limbs[2] &= LOW_51_BIT_MASK;
        limbs[3] &= LOW_51_BIT_MASK;
        limbs[4] &= LOW_51_BIT_MASK;

        limbs[0] += carry4 * 19;
        limbs[1] += carry0;
        limbs[2] += carry1;
        limbs[3] += carry2;
        limbs[4] += carry3;

        return FieldElement(limbs);
    }
}