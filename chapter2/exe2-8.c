unsigned rightsort(unsigned x, int n)
{
    while(n-- > 0)
    {
        if((x & 1) == 1)
        {
            x = (x >> 1) | ~(~0U >> 1);
        }
        else
        {
            x = (x >> 1);
        }
    }
    return x;
}

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     unsigned i = 011;
//     printf("%u", rightsort(i, 2));
//     return 0;
// }
