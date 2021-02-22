#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*first = NULL;

typedef struct Node Node;

Node *initNode(int num){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=num;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}