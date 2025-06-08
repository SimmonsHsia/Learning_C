#include <stdio.h>

int main(int argc, char const *argv[])
{
    char amessage[] = "now is the time";
    char *pmessage = "now is the time";

    printf("previous amessage is %s\n", amessage);
    printf("previous pmessage is %s\n", pmessage);
    *pmessage += 1; // 错误! 注意区分数组指针和字符指针
    printf("current amessage is %s\n", amessage);
    printf("current pmessage is %s\n", pmessage);

    return 0;
}
