#include <stdio.h>

/* 回显程序命令行参数；版本1 */
int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++)
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    printf("\n");
    return 0;
}
