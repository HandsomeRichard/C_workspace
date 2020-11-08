#include <stdio.h>
#include <stdlib.h>



struct Node
{
    int data;
    struct Node* next;
};

struct Node* addFirst(struct Node* head, int value);
void printAll(struct Node*);
struct Node* append(struct Node*,int value);

int main(int argc, char const *argv[])
{
    
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head  = (struct Node*)malloc(sizeof(struct Node));
    second  = (struct Node*)malloc(sizeof(struct Node));
    third  = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("head = %x\n",&head);
    head = addFirst(head,9);
    
    head = append(head,123);

    printAll(head);
    return 0;
}


struct Node* append(struct Node* head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    struct Node *last = head; 
    newNode->data = value;
    newNode->next = NULL;


    //find Last
     /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 

    last->next = newNode;
    
    return head;
}

struct Node* addFirst(struct Node* head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;

    return newNode;
}

void printAll(struct Node* head)
{
    //count size of linklist
       while (head != NULL) { 
        printf(" %d ", head->data); 
        head = head->next; 
    } 

}