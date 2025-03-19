#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
int getline(char s[], int lim);

void reverse(char s[])
{
    int i = 0, len = 0;
    while(s[i] != '\0')
        i++;
    len = i;
    char temp[len];
    len = len - 1;
    for(i = 0; i < (len + 1) / 2; i++)
    {
        temp[len - i] = s[len - i];
        s[len - i] = s[i];
        s[i] = temp[len - i];
    }
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

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int len = 0;
    while((len = getline(line, MAXLINE)) > 0)
    {
        line[len - 1] = '\0';
        reverse(line);
        printf("%s\n", line);
    }
    return 0;
}
