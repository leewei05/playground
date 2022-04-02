#include <stdio.h>
#include <stdint.h>

uint32_t average(uint32_t low, uint32_t high)
{
    return low + (high - low) / 2;
}

int main()
{
    int low = 3;
    int high = 5;
    printf("average is %u", average(low, high));

    return 0;
}




