#include <stdio.h>

#define carre1(X) X*X
#define carre2(X) X*(X)
#define carre3(X) (X)*(X)

int main()
{
    int n = 5;
    printf("%d\n", carre1(n+3) );
    printf("%d\n", carre2(n+3) );
    printf("%d\n", carre3(n+3) );
}