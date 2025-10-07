#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    int tab[100];
    int size = 10;
    int maxrandval = 50;

    for (int i = 0; i < size; i++){
        tab[i] = rand() % maxrandval;
        printf("%d\n", tab[i]);
    }

    printf("Minimum : %d\n", mini(tab, size));
    printf("Indice minimum : %d\n", imini(tab, size));
    printf("Maximum : %d\n", maxi(tab, size));
    printf("Indice maximum : %d\n", imaxi(tab, size));
    printf("Somme : %d\n", somme(tab, size));
    printf("Moyenne : %lf\n", moyenne(tab, size));
    printf("Nombre de valeurs t entre 36 et 43 : %d\n", compte(tab, size, 36, 43));
    printf("est trié ? %d\n", est_trie(tab, size));
    return 0;
}