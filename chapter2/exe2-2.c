#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    char c = 0;
    int lim = 5;
    char s[10];
    
    for(i = 0; i < lim - 1; )
        if((c = getchar()) != '\n')
            if(c != EOF)
                s[i] = c;
                i++;
    return 0;
}
