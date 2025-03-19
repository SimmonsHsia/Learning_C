#include <stdio.h>
#define MAXLINE 1000

int getlines(char s[], int lim);

int getlines(char s[], int lim)
{
    int i = 0;
    char c = 0;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF; i++)
        s[i] = c;
    s[i] = '\0';
    return i;
}

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int len = getlines(line, MAXLINE);
    int i = 0;

    int num_ykh = 0;
    int num_fkh = 0;
    int num_hkh = 0;

    int in_quote = 0;
    int is_comment = 0;
    int is_comments = 0;
    
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
            {
                if(line[i] == '(')
                    num_ykh++;
                if(line[i] == ')')
                    num_ykh--;
                if(line[i] == '[')
                    num_fkh++;
                if(line[i] == ']')
                    num_fkh--;
                if(line[i] == '{')
                    num_hkh++;
                if(line[i] == '}')
                    num_hkh--;
            }

            
        }
    }
    if(num_ykh != 0)
        printf("圆括号使用错误！");
    if(num_fkh != 0)
        printf("方括号使用错误！");
    if(num_hkh != 0)
        printf("花括号使用错误！");
    if(num_ykh == 0 && num_hkh == 0 && num_fkh == 0)
        printf(":-) 无基本语法错误");
    return 0;
}
