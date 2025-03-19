/* getbits函数：返回x中从第p位开始的n位 */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) && ~(~0 << n);
}
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i = 111 & ~0;
    printf("%d", i);
    return 0;
}
