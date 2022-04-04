#include <stdio.h>

static void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

static void print_array(int a[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d", a[i]);

    printf("\n");
}

static void reverse_array(int a[], int len)
{
    int first, last;
    print_array(a, len);
    for (first = 0, last = len - 1; first < last; first++, last--)
        inplace_swap(&a[first], &a[last]);

    print_array(a, len);
}

int main()
{
    int even[4] = {1, 2, 3, 4};
    int odd[5] = {1, 2, 3, 4, 5};

    reverse_array(even, sizeof(even)/sizeof(int));
    reverse_array(odd, sizeof(odd)/sizeof(int));
}
