#include <stdio.h>

int main(int argc, char const *argv[])
{
    double sum = 0;
    double num;

    while (scanf("%lf", &num) != EOF)
    {
        sum += num;
        printf("sum = %lf\n", sum);
    }
    return 0;
}
