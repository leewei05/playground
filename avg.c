#include <stdio.h>
#include <stdint.h>

uint32_t average(uint32_t low, uint32_t high)
{
    return low + (high - low) / 2;
}

uint32_t average_bitwise(uint32_t a, uint32_t b)
{
    return (a >> 1) + (b >> 1) + (a & b & 1);
}

uint32_t average_bitadder(uint32_t a, uint32_t b)
{
    return (a & b) + ((a ^ b) >> 1);
}

int main()
{
    int low = 3;
    int high = 5;
    printf("average is %u", average(low, high));

    return 0;
}




