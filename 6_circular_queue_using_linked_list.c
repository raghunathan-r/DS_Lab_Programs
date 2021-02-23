#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

typedef struct Node Node;

Node *initNode(int num){
    Node *temp;
    temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL){
        printf("ERROR memeory full\n");
        return NULL;
    }else{
        temp->data=num;
        temp->next=NULL;
        return temp;
    }
}

void enqueue(int num){
    Node *temp=initNode(num);
    if(front==NULL && rear==NULL){
        temp->next=front;
        rear=front=temp;
    }else{
        rear->next=temp;
        temp->next=front;
        rear=temp;
    }
}

int dequeue(){
    Node *temp=front;
    int deletedElement;

    if(front==NULL && rear==NULL){
        printf("ERROR queue is empty\n");
        return 0;
    }else if(front==rear){
        front=rear=NULL;
        deletedElement=temp->data;
        free(temp);
    }else{
        front=front->next;
        rear->next=front;
        deletedElement=temp->data;
        free(temp);
    }
    return deletedElement;
}

void display(){
    Node *temp=front;
    if(front==NULL && rear==NULL){
        printf("ERROR Queue is empty\n");
        return;
    }else{
        do{
            printf("%d\t", temp->data);
            temp=temp->next;
        }while(temp!=front);
        printf("\n\n");
    }
}

int main()
{
    int ch;
    printf("\n1. Add element\n2. Delete element\n3.Display queue\n4.Exit\n\n");
    
    do
    {
        printf("\nEnter the option corresponding to your desired choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                {
                    int num;
                    printf("Enter the element to be added : ");
                    scanf("%d", &num);
                    enqueue(num);
                    break;
                }
            case 2:
                {
                    printf("The deleted element is : %d\n", dequeue());
                    break;
                }
            case 3:
                {
                    display();
                    break;
                }
            case 4:
                {
                    printf("Thank you\n\n");
                    return 0;
                }
            default:
                printf("INVALID INPUT TRY AGAIN\n");
                break;
        }        
    } while (ch != 4);
}