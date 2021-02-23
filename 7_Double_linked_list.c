#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*head = NULL, *tail=NULL;

typedef struct Node Node;

Node *initNode(int num){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=num;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

void insertAtBegining(int num){
	Node *temp=initNode(num);
	if(head==NULL){
		temp->next=NULL;
        temp->prev=NULL;
        head=tail=temp;
	}else{
		temp->next=head;
        temp->prev=NULL;
		head=temp;
	}
}

void insertAtEnd(int num){
    Node *temp=initNode(num);
    if(head==NULL){
        insertAtBegining(num);
    }else{
        temp->prev=tail;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
}

int lengthOfList(){
    Node *temp=head;
    int count=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("ALERT : List length -> %d\n", count);
    return count;
}

void insertAtPos(int num, int pos){
    Node *p=head, *q, *temp;
    if(pos>lengthOfList()){
        printf("ERROR unable to add to list\n");
        return;
    }
    for(int i=0; i<pos-1; i++){
        p=p->next;
    }
    temp=initNode(num);
        temp->prev=p;
        temp->next=p->next;
    if(p->next!=NULL){
        p->next->prev=temp;
    }
    p->next=temp;
}

void displayFromBegining(){
    Node *temp=head;
	while(temp!=NULL){
		printf("%d\t", temp->data);
		temp=temp->next;
	}
	printf("\n\n");
}

int deleteInBeg(){
    Node *temp;
    int deletedElement;
    if(head==NULL){
        printf("ERROR list is empty\n");
        return 0;
    }else{
        temp=head;
        head->next->prev=NULL;
        head=head->next;
        deletedElement=temp->data;
    }
    free(temp);
    return deletedElement;
}

int deleteInEnd(){
    Node *temp;
    int deletedElement;
    if(tail==NULL){
        printf("ERROR list is empty\n");
        return 0;
    }else{
        temp=tail;
        tail->prev->next=NULL;
        tail=tail->prev;
        deletedElement=temp->data;
    }
    free(temp);
    return deletedElement;
}

int deleteAtPos(int pos){
    Node *p=head, *temp;
    if(pos>lengthOfList()){
        printf("ERROR element not added\n");
        return 0;
    }else{
        for(int i=lengthOfList(); i>pos+1; i--){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next!=NULL){
            p->next->prev=p->next;
        }
    }
}

int main(){
	int choice, num, pos;

	printf("\n\n1. Insert in begining\n2. Insert at end\n3. Insert in position\n");
	printf("4. Delete in begining\n5. Delete at end\n6. Delete in position\n");
	printf("7. Display list form beg\n8. Display list from end\n9. Exit\n\n");

	do{
		printf("___________________________\n");
		printf("Choice ?= ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter number to insert : ");
			scanf("%d", &num);
			insertAtBegining(num);
			break;
		case 2:
			printf("Enter number to insert : ");
			scanf("%d", &num);
			insertAtEnd(num);
			break;
		case 3:
			printf("Enter number to insert and position respectively :-\n");
			scanf("%d %d", &num, &pos);
			insertAtPos(num, pos);
			break;
		case 4:
			num=deleteInBeg();
			if(num){
				printf("Deleted element : %d\n", num);
			}
			break;
		case 5:
			num=deleteInEnd();
			if(num){
				printf("Deleted element : %d\n", num);
			}
			break;
		case 6:
			printf("Enter position to delete : ");
			scanf("%d", &pos);
            num=deleteAtPos(pos);
            if(num){
                printf("Deleted element : %d\n", num);
            }
            break;
		case 7:
			displayFromBegining();
			break;
		default:
			break;
		}
	}while(choice!=9);
}
