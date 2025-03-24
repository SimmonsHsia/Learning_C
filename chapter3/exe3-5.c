#include <string.h>
#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

void itob(int n, char s[], int b)
{
    int i;

    for(i = 0; n > 0; i++) {
        if((n % b) < 10)
            s[i] = n % b + '0';
        else
            s[i] = n % b - 10 + 'a';
        n /= b;
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main(int argc, char const *argv[])
{
    char s[1000];
    itob(15, s, 16);
    printf("s:\n%s", s);
    return 0;
}
