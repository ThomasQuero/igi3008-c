#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int getRandomInteger(int rmin, int rmax){
    return rmin + rand() % (rmax - rmin + 1);
}

void freeList(Node* head){
    while (head){
        Node* next = head->next;
        free(head);
        head = next;
    }
}

int listLength(Node* head){
    int nb = 0;
    while (head != NULL){
        nb++;
        head = head->next;
    }
    return nb;
}

void printList(Node* head){
    while (head != NULL){
        printf("Adresse mémoire : %p\nValeur : %d\nAdresse suivant : %p\n\n",
            (void*)head, head->data, (void*)head->next);
        head = head->next;
    }
}

int isEmpty(Node* head){
    return head == NULL;
}

Node* insertNodeAtFirst(Node* head, int data)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

Node* insertNodeAtEnd(Node* head, int data){
    Node *n = malloc(sizeof(Node));
    if (!n) return head;
    n->data = data;
    n->next = NULL;

    if (head == NULL) return n;

    Node *cur = head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = n;
    return head;
}

Node* insertNodeAtIndex(Node* head, int data, int index){
    if (index < 0) return head;
    if (index == 0) {
        Node *n = malloc(sizeof(Node));
        if (!n) return head;
        n->data = data;
        n->next = head;
        return n;
    }
    Node *cur = head;
    for (int i = 0; i < index-1 && cur != NULL; i++) cur = cur->next;
    if (cur == NULL) return head;
    Node *n = malloc(sizeof(Node));
    if (!n) return head;
    n->data = data;
    n->next = cur->next;
    cur->next = n;
    return head;
}

Node* deleteFirstNode(Node* head){
    if (head == NULL) return NULL;
    Node *next = head->next;
    free(head);
    return next;
}

Node* deleteLastNode(Node* head){
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node *prev = head, *cur = head->next;
    while (cur->next != NULL) { prev = cur; cur = cur->next; }
    prev->next = NULL;
    free(cur);
    return head;
}

Node* deleteNodeAtIndex(Node* head, int index){
    if (index < 0 || head == NULL) return head;
    if (index == 0) {
        Node *next = head->next;
        free(head);
        return next;
    }
    Node *prev = head;
    for (int i = 0; i < index-1 && prev != NULL; i++) prev = prev->next;
    if (prev == NULL || prev->next == NULL) return head;
    Node *to_del = prev->next;
    prev->next = to_del->next;
    free(to_del);
    return head;
}

int main(void) {
    srand(time(NULL));

    Node *head = NULL; // liste vide au départ
    printf("Liste initiale : %s\n\n", isEmpty(head) ? "vide" : "non vide");

    // Insertion de quelques éléments en tête
    for (int i = 0; i < 3; i++) {
        int val = getRandomInteger(10, 99);
        head = insertNodeAtFirst(head, val);
        printf("Ajout %d au début\n", val);
    }
    printf("\n--- Après insertions au début ---\n");
    printList(head);
    printf("Longueur : %d\n\n", listLength(head));

    // Insertion de quelques éléments en fin
    for (int i = 0; i < 3; i++) {
        int val = getRandomInteger(100, 199);
        head = insertNodeAtEnd(head, val);
        printf("Ajout %d à la fin\n", val);
    }
    printf("\n--- Après insertions à la fin ---\n");
    printList(head);
    printf("Longueur : %d\n\n", listLength(head));

    // Insertion à un index précis
    head = insertNodeAtIndex(head, 555, 2);
    printf("Insertion de 555 à l’index 2\n");
    printList(head);
    printf("Longueur : %d\n\n", listLength(head));

    // Suppression du premier élément
    head = deleteFirstNode(head);
    printf("--- Après suppression du premier élément ---\n");
    printList(head);
    printf("Longueur : %d\n\n", listLength(head));

    // Suppression du dernier élément
    head = deleteLastNode(head);
    printf("--- Après suppression du dernier élément ---\n");
    printList(head);
    printf("Longueur : %d\n\n", listLength(head));

    // Suppression à un index précis
    head = deleteNodeAtIndex(head, 2);
    printf("--- Après suppression de l’élément à l’index 2 ---\n");
    printList(head);
    printf("Longueur : %d\n\n", listLength(head));

    // Libération de la mémoire
    freeList(head);
    printf("Liste libérée.\n");

    return 0;
}