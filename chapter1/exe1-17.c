#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);


int main(int argc, char const *argv[])
{
    int len;

    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0)
    {
        if(len > 8)
        {
            printf("该行长度为%d:\n%s", len, line);
        }
    }

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