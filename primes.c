// primes.c

#include <stdio.h>

int isprime(int p){
    int i = 2;
    while(i < p){
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