#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);


int main(int argc, char const *argv[])
{
    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0)
    {
        int i = len - 2;
        while(i >= 0 && (line[i] == '\t' || line[i] == ' '))
        {
            line[i] = '\n';
            line[i + 1] = '\0';
            i--;
        }
        printf(line);
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

