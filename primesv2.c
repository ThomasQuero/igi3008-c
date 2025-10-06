// primes.c
#include <math.h>
#include <stdio.h>

double sqrt(double arg);

int isprime(int p){
    if(p <= 2) return 1;
    if(p % 2 == 0) return 0;
    int i = 2;
    while(i < p){
        if(i % 2 == 0 || i > (int)sqrt(p) + 1){
            i++;
            continue;
        }
        if((p % i) == 0) return 0;
        i++;
    }
    return 1;
}

int main(){
    int x = 3;
    isprime(x) ? printf("%d est premier\n", x): printf("%d n'est pas premier\n", x);
    x = 8;
    isprime(x) ? printf("%d est premier\n", x): printf("%d n'est pas premier\n", x);
    x = 11;
    isprime(x) ? printf("%d est premier\n", x): printf("%d n'est pas premier\n", x);
    return 0;
}