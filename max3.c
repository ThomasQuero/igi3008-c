#include <stdio.h>

int max3(int a, int b, int c){
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b :  c);
}

int main(){
    int x = 2;
    int y = 8;
    int z = 5;
    printf("max entre :%d, %d, %d est %d\n", x, y, z, max3(x, y, z));
    printf("max entre :%d, %d, %d est %d\n", x, y, z, max3(y, z, x));
    printf("max entre :%d, %d, %d est %d\n", x, y, z, max3(z, x, y));
    return 0;
}