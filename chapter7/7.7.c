#include <stdio.h>

/* fgets函数：从iop指向的文件中最多读取n-1个字符，再加上一个NULL */
char *fgets(char *s, int n, FILE *iop)
{
    register int c;
    register char *cs;

    cs = s;
    while (--n > 0 && (c = getc(iop)) != EOF)
        if ((*cs++ = c) == '\n')
            break;
    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}

/* fputs函数：将字符串s输出到iop指向的文件中 */
int fputs(char *s, FILE *iop)
{
    int c;

    while (c = *s++)
        putc(c, iop);
    return ferror(iop) ? EOF : 1;
}

/* getline函数：读入一个输入行，并返回其长度 */
int getline(char *line, int max)
{
    if (fget(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}