int bitcount_v2(unsigned x)
{
    int b = 0;
    while(x)
    {
        x &= (x - 1);
        b++;
    }
    return b;
}

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     unsigned int i = 7;
//     printf("%d", bitcount_v2(i));
//     return 0;
// }
