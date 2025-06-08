#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c = 0, sn = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++sn;
        }
    }
    printf("空格的个数为%d\n", sn);
    return 0;
}
