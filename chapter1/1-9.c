#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar(c);
            while ((c = getchar()) == ' ')
            {
                ;
            }
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}
