#include <stdio.h>
#define MAXLINE 1000

int getlines(char s[], int lim);

int getlines(char s[], int lim)
{
    int c, i;
    
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

int main(int argc, char const *argv[])
{
    int i = 0;
    int len = 0;
    char line[MAXLINE];
    int in_quote = 0;
    int is_comment = 0;
    int is_comments = 0;
    len = getlines(line, MAXLINE);
    for(i = 0; i < len; i++)
    {
        if(in_quote == 0 && line[i] == '"')
            in_quote = 1;
        if(in_quote = 1 && line[i] == '"')
            in_quote = 0;
        if(in_quote == 0)
        {
            if(line[i] == '/' && line[i+1] == '/')
                is_comment = 1;
            if(is_comment == 1 && line[i] == '\n')
                is_comment = 0; 
            
            if(line[i] == '/' && line[i+1] == '*')
                is_comments = 1;
            if(is_comments == 1 && line[i-2] == '*' && line[i-1] == '/')
                is_comments = 0;

            if(is_comment != 1 && is_comments != 1)
                putchar(line[i]);
            
        }
        else
        {
            putchar(line[i]);
        }
    }
    return 0;
}
