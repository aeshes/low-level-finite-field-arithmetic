#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


uint64_t widening_mul(uint32_t x, uint32_t y)
{
	return (uint64_t)x * (uint64_t)y;
}


int main(int argc, char *argv[])
{
	uint32_t x = 0xAAAAAAAA;
	uint32_t y = x;

	uint64_t r = widening_mul(x, y);

	printf("%s\n", PRIu64);
	printf("%" PRIu64 "\n", r);
}
