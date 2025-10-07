#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int order_and_display(int* t1, int size1, int* t2, int size2){
    int size = 0;
    int t1val = 0;
    int t2val = 0;
    int k = 0;
    int t3[size1 + size2];

    (size1 > size2) ? (size = size2) : (size = size1);
    for (int i = 0; i < size; i++){
        if(*(t1+t1val) > *(t2+t2val)){
            t3[i] = *(t2 + t2val);
            t2val++;
        }
        else {
            t3[i] = *(t1 + t1val);
            t1val++;
        }
        k++;
    }
    while (t1val < size1) t3[k++] = t1[t1val++];
    while (t2val < size2) t3[k++] = t2[t2val++];

    printf("Tableau final : [");
    for(int i = 0; i < size1 + size2; i++){
        printf("%d, ", t3[i]);
    }
    printf("]\n");

    return size1 + size2;
}

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Erreur dans les arguments\n");
        exit(-1);
    }

    srand(time(NULL));
    int *t1;
    int *t2;

    t1 = calloc(atoi(argv[1]), sizeof(int));
    t2 = calloc(atoi(argv[1]), sizeof(int));

    int size1 = rand() % 10 + 10;
    int size2 = rand() % 10 + 10;

    t1[0] = rand() % 5;
    t2[0] = rand() % 5;

    for (int i = 1; i < size1; i++){
        t1[i] = t1[i-1] + rand() % atoi(argv[2]);
    }

    for (int i = 1; i < size2; i++){
        t2[i] = t2[i-1] + rand() % atoi(argv[2]);
    }

    printf("Tableau 1 : [");
    for (int i = 0; i < size1; i++){
        printf("%d, ", t1[i]);
    }
    printf("]\n");

    printf("Tableau 2 : [");
    for (int i = 0; i < size2; i++){
        printf("%d, ", t2[i]);
    }
    printf("]\n");

    printf("Nombre d'éléments : %d\n", order_and_display(t1, size1, t2, size2));

    free(t1);
    free(t2);
}