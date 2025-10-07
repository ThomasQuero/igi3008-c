#include <stdio.h>
#include <stdlib.h>


int mini(int t[], int size){
    int min = t[0];

    for (int i = 1; i < size; i++){
        if(t[i] < min) min = t[i];
    }
    return min;
}

int imini(int t[], int size){
    int min = 0;

    for (int i = 1; i < size; i++){
        if(t[i] < t[min]) min = i;
    }
    return min;
}

int maxi(int t[], int size){
    int max = t[0];

    for (int i = 1; i < size; i++){
        if(t[i] > max) max = t[i];
    }
    return max;
}

int imaxi(int t[], int size){
    int max = 0;

    for (int i = 1; i < size; i++){
        if(t[i] > t[max]) max = i;
    }
    return max;
}

int somme(int t[], int size){
    int somme = 0;

    for (int i = 0; i < size; i++){
        somme += t[i];
    }

    return somme;
}

double moyenne(int t[], int size){
    return (double)somme(t, size)/size;
}

int compte(int t[], int size, int lowest, int highest){
    int nb = 0;

    for ( int i = 0; i < size; i++){
        if(t[i] >= lowest && t[i] <= highest) nb++;
    }
    return nb;
}

int est_trie(int t[], int size) {
    if (size < 2) return 1;

    int croissant = 1;
    int decroissant = 1;

    for (int i = 1; i < size; i++) {
        if (t[i] < t[i - 1]) croissant = 0;
        if (t[i] > t[i - 1]) decroissant = 0;
    }

    if (croissant) return 1;
    if (decroissant) return -1;
    return 0;
}

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