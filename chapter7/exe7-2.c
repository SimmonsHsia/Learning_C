#include <stdio.h>
#include <string.h>

#define MAXLINE 15

int main(int argc, char const *argv[])
{
    int mode = 10, count = 0, c;

    if (argc == 2)
    {
        if (strcmp(argv[1], "-o") == 0)
            mode = 8;
        else if (strcmp(argv[1], "-x") == 0)
            mode = 16;
        else
            printf("Usage: print [ -o | -x ]\n");
    }
    printf("mode = %d\n", mode);

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            count = 0;
        }
        else if (count > MAXLINE)
        {
            count = 0;
            putchar('\n');
        }
        else
            count++;

        switch (mode)
        {
        case 10:
            putchar(c);
            break;

        case 8:
            printf("0%o", c);
            break;

        case 16:
            printf("0x%x", c);
            break;

        default:
            putchar(c);
            break;
        }
    }

    return 0;
}
