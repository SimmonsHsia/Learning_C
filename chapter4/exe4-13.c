#include <string.h>
#include <stdio.h>

void reverse(char s[])
{
    static int i = 0;
    static int len = 0;
    len = strlen(s);

    char temp;
    temp = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = temp;

    if (i < len - 1 - i)
    {
        i += 1;
        reverse(s);
    }
}

int main(int argc, char const *argv[])
{
    char s[6] = "olleh";
    reverse(s);
    printf("%s", s);
    return 0;
}
