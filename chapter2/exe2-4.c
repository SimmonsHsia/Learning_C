#include <stdio.h>

void squeeze(char s[], char t[]);

void squeeze(char s[], char t[])
{
    int i, j, k;

    for(k = 0; t[k] != '\0'; k++)
    {
        for(i = j = 0; s[i] != '\0'; i++)
        {
            if(s[i] != t[k])
                s[j++] = s[i];
        }
        s[j] = '\0';
    }
}

int main(int argc, char const *argv[])
{
    char s[100], t[100];
    printf("raw strings:\n");
    scanf("%s", s);
    printf("strings to be deleted:\n");
    scanf("%s", t);
    squeeze(s,t);
    printf("new strings:%s", s);
    return 0;
}
