#include <limits.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
    char s[100];
    itoa(1214321, s);
    printf("%s", s);
    return 0;
}


void itoa(int n, char s[])
{
    int i, sign;

    if(n == INT_MIN) {
        char t[] = "-2147483648";
        for(i = 0; t[i] != '\0'; i++)
            s[i] = t[i];
        s[i] = '\0';
    }
    else {
        if ((sign = n) < 0)
            n = -n;
        i = 0;
        do {
            s[i++] = n % 10 + '0';
        } while((n /= 10) > 0);
        if(sign < 0)
            s[i++] = '-';
        s[i] = '\0';
        reverse(s);
    }
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