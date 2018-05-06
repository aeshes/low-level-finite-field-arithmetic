#include <cstdint>
#include <cstdio>

struct big_t
{
	uint64_t hi;
	uint64_t lo;

	big_t operator~() const
	{
		return {~hi, ~lo};
	}

	big_t operator|(const big_t& rhs) const
	{
		return { hi | rhs.hi, lo | rhs.lo};
	}

	big_t & operator|=(const big_t& rhs)
	{
		hi |= rhs.hi;
		lo |= rhs.lo;

		return *this;
	}
}

int main()
{

}
