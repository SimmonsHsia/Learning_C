#include <stdio.h>
#define OUT 1
#define IN 0

int main(int argc, char const *argv[])
{
    int c = 0, state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
                printf("\n");
            state = OUT;
        }
        else
        {
            putchar(c);
            state = IN;
        }
    }
    return 0;
}
