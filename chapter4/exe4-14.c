#define swap(t, x, y) \
    {                 \
        t = x;        \
        x = y;        \
        y = t;        \
    }

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 1;
    int y = 5;
    int t = 0;
    printf("x = %d, y = %d\n", x, y);
    swap(t, x, y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
