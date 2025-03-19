/* squeeze函数：从字符串s中删除字符c */
void sequeeze(char s[], int c)
{
    int i, j;

    for(i = j = 0; s[i] != '\0'; i++)
        if(s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}