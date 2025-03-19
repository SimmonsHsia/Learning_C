#include <stdio.h>
#define N 8

int main(int argc, char const *argv[])
{
    int c = 0, i = 0, j = 0;
    while((c = getchar()) != EOF)
    {
        
        if(c == '\t') {
            for(j = 0; j < N - i; ++j) {
                putchar('*');
            }
        }
        else
            putchar(c);

        if(i < N - 1)
            ++i;
        else
            i = 0;
        if(c == '\n')
            i = 0;
    }

    return 0;
}