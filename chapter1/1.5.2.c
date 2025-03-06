#include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     long nc = 0;
//     while (getchar() != 'EOF')
//     {
//         ++nc;
//     }
//     printf("%ld\n", nc);
//     return 0;
// }

int main(int argc, char const *argv[])
{
    double nc = 0.0;

    for (nc = 0; getchar() != 'q'; ++nc)
    {
        ;
    }
    printf("%.0f\n", nc);
    return 0;
}
