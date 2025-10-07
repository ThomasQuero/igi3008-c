// str.c

#include <stdio.h>

int main()
{
    char s[] = "Hello World !";

    for (int i=0 ; s[i]!='\0' ; i++)
        printf("i = %2d, s[%2d] = %c, &s[%2d] = %p\n", i, i, s[i], i, &s[i]);

return 0;
}