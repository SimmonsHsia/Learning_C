#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy (char to[], char from[]);

int main(int argc, char const *argv[])
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0)
    {
        printf("该行含有%d个字符: %s", len, line);
        if(len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0)
        printf("最长行含有%d个字符: %s", max, longest);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
