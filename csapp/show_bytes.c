#include <stddef.h>
#include <stdio.h>

typedef unsigned char *byte_pointer;

// start is the starting address of a consecutive array
// each array slot is an unit of its type, here is byte_pointer type, which is unsigned char
void show_bytes(byte_pointer start, size_t len)
{
    for (size_t i = 0; i < len; i++)
        printf("%.2x ", start[i]);
    printf("\n");
}

void show_int(int x)
{
    // this tells the compiler to force cast &x to type byte_pointer
    // it won't change the value of the pointer
    // the compiler will change the data type of the data that the pointer is pointing to
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    // void * is a special pointer that doesn't point to any data types
    // it forces us to cast to any type before we dereference from it
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main()
{
    int ival = 12345;
    float fval = (float) 12345.0;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);

    return 0;
}
