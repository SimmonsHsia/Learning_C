#include<stdio.h>
#define N 8
#define MAXLINE 1000

int getline(char s[], int lim);

int getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main(int argc, char const *argv[])
{
	int len = 0, i = 0;
    int start = 0, num = 0;
    int nt = 0, ns = 0;
	char line[MAXLINE];

	while((len = getline(line, MAXLINE)) > 0)
	{

        for(i = 0; i < len; ++i) {

            if(line[i] == ' ') {
                if(num == 0) {
                    start = i;
                    num++;
                }
                else {
                    num++;
                }
            }

            if(line[i] != ' ') {
                if(num == 0) {
                    putchar(line[i]);
                }
                else {
                    start %= N;

                    if((start + num) / N) {
                        for(nt = 0; nt < ((start + num) / N); nt++)
                        putchar('\t');
                        for(ns = 0; ns < ((start + num) % N); ns++)
                        putchar('*');
                    }
                    else {
                        for(ns = 0; ns < num; ns++)
                        putchar('*');
                    }
                    
                    putchar(line[i]);
                    num = 0;
                    start = 0;
                }
            }
        }
        num = 0;
        start = 0;
	}
    
	return 0;
}
