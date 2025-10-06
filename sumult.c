#include <stdio.h>

void sumult(int a, int b, int *pointeursum, int *pointeurmult){
    *pointeursum = a + b;
    *pointeurmult = a * b;
}

int main(){
    int a = 3;
    int b = 4;
    int ressum = 0;
    int resmult = 0;

    sumult(a, b, &ressum, &resmult);

    printf("%d + %d = %d\n%d * %d = %d\n", a, b, ressum, a, b, resmult);
    return 0;
}