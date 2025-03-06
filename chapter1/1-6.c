#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    a = (getchar() != EOF);
    printf("%d", a);
    return 0;
}
