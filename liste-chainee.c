#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int getRandomInteger(int rmin, int rmax){
    return rand() % rmax + rmin;
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
        printf("Adresse mémoire : %p\nValeur : %d\nAdresse suivant : %p\n\n"
                , head, head->data, head->next);
        head = head->next;
    }
}

int isEmpty(Node* head){
    return head->next == NULL;
}

Node* insertNodeAtFirst(Node* head, int data)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

Node* insertNodeAtEnd(Node* head, int data){
    if (isEmpty(head)) return head;

    while(head != NULL){
        head = head->next;
    }

    Node* end = malloc(sizeof(Node));
    end->data = data;
    end->next = NULL;
    head->next = end;
    return; 
}

int main()
    {

        Node* head;

        int data;
        int nnodes;

        // Build list with insertNodeAtEnd()

        nnodes = 10;
        head = NULL;
        printf("STARTING with an empty list\n");
        for (int n = 0; n < nnodes; n++)
        {
            data = getRandomInteger(1, 50);
            printf("... inserting %3d at end\n", data);
            head = insertNodeAtEnd(head, data);
        }
        printf("DONE\n");
        printList(head);
        printf("length = %d\n", listLength(head));
        fprintf(stderr, "***\n");

        return 0;
    }