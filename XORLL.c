#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nxp;
};

struct Node* XOR(struct Node* a, struct Node* b){
    return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node* insert(struct Node** head, int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;

    if (*head == NULL)
        node->nxp = XOR(NULL, NULL); // Stores XOR of previous and next pointer


    else{
        struct Node* curr = *head;

        curr->nxp = XOR(node,curr->nxp); // Update curr node address
        node->nxp = XOR(NULL, curr);     // Update new node address
    }

    *head = node;
    return *head;
}

void printList(struct Node** head){
    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* next;

       if (head == NULL)
        printf("List is empty");

    // Forward Traversal of XOR linked list
    while (curr != NULL){
        printf("%d ", curr->data);

        next = XOR(prev, curr->nxp);
        prev = curr;
        curr = next;
    }
}

struct Node* delEnd(struct Node** head){
    if (*head == NULL)
        printf("List is empty");

    else
    {
        struct Node* curr = *head;
        struct Node* prev = NULL;
        struct Node* next;

        // Forward Traversal XOR linked list
        while (XOR(curr->nxp, prev) != NULL){
            next = XOR(prev, curr->nxp);
            prev = curr;
            curr = next;
        }
        if (prev != NULL)
            prev->nxp = XOR(XOR(prev->nxp, curr), NULL);

        else
            *head = NULL;

        free(curr);
    }
    return *head;
}

void main(){

    int data,choice;
    struct Node* head = NULL;

     printf("\n********************* MENU *******************\n");
     printf(" 1. Insert\n 2. Delete\n 3. Display the list\n 4. Exit\n");
     printf("\n**********************************************\n\n");
    while(1){

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice){
        case 1: printf("Enter the data : ");
                scanf("%d",&data);
                insert(&head, data);
                break;

        case 2: delEnd(&head);
                break;

        case 3: printList(&head);
                break;

        case 4: exit(0);

        default: printf("\nInvalid Choice\n");
        }
    }
}

