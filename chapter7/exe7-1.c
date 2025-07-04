#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int c;

    while ((c = *argv[0]++) != '\0')
    {
        if (islower(c))
            putchar(toupper(c));
        else
            putchar(tolower(c));
    }
    return 0;
}
