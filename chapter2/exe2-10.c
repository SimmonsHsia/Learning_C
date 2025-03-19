/* 原lower函数：
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 'a' - 'A';
    }
    else
    {
        return c;
    }
}
*/

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     printf("%c", lower('1'));
//     return 0;
// }
