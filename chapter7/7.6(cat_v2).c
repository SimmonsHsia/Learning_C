#include <stdio.h>
#include <stdlib.h>

/* cat函数：连接多个版本，版本2 */
int main(int argc, char const *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0]; // 记下程序名，供错误处理用

    if (argc == 1) // 如果命令行不带参数，则复制标准输入
        filecopy(stdin, stdout);
    else
    {
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}
