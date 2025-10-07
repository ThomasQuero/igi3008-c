#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char s[100];
    // char *p = s;
    // int i = 0;
    // printf("Entrez une chaine de caractères : %s\n", s);
    // fgets(s, 100, stdin);
    // while (*p != '\0'){
    //     printf("Caractère %d : %c\n", i, *p);
    //     p++;
    //     i++;
    // }

    printf("Entrez une chaines de caractères : %s\n", s);
    fgets(s, 100, stdin);
    printf("Chaine récupérée : %s\n", s);
    int val = atoi(s);
    printf("Valeur multipliée par 2 = %d\n", val*2);
    return 0;
}