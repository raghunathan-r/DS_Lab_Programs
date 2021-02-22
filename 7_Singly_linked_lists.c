#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*head=NULL;

typedef struct Node Node;

Node *initNode(int num){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=num;
	temp->next=NULL;
	return temp;
}

void insertAtBegining(int num){
	Node *temp=initNode(num);
	if(head==NULL){
		temp->next=NULL;
		head=temp;
	}else{
		temp->next=head;
		head=temp;
	}
}

void insertAtEnd(int num){
	Node *temp=head;
	while (temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=initNode(num);
}

void insertAtPos(int num, int pos){
	Node *p=head, *q;
	for(int i=0; i<pos-1; i++){
		q=p;
		p=p->next;
	}
	q->next=initNode(num);
	q->next->next=p;
}

int deleteInBeg(){
	int deletedElement;
	Node *temp;
	if(head==NULL){
		printf("ERROR list is empty\n");
		return 0;
	}else{
		deletedElement=head->data;
		temp=head;
		head=head->next;
	}
	free(temp);
	return deletedElement;
}

int deleteInEnd(){
	int deletedElement;
	Node *temp, *p=head, *q;
	if(head==NULL){
		printf("ERROR list is empty\n");
		return 0;
	}else{
		while (p->next!=NULL)	
		{	
			q=p;
			p=p->next;
		}
		deletedElement=p->data;
		if(p==head){
			head=NULL;
		}else{
			q->next=NULL;
		}
		free(p);
	}
	return deletedElement;
}

int deleteAtPos(int pos){
	Node *p=head, *q;
	int deletedElement, i=0;

	for(i=0; i<pos-1; i++){
		q=p;
		p=p->next;
	}

	deletedElement=p->data;
	if(p==head){
		head==NULL;
	}else{
		q->next=p->next;
	}
	free(p);
	return deletedElement;
}

void display(){
	Node *temp=head;
	while(temp!=NULL){
		printf("%d\t", temp->data);
		temp=temp->next;
	}
	printf("\n\n");
}

int main(){
	int choice, num, pos;

	printf("\n\n1. Insert in begining\n2. Insert at end\n3. Insert in position\n");
	printf("4. Delete in begining\n5. Delete at end\n6. Delete in position\n");
	printf("7. Display list\n8. Exit\n\n");

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
			printf("Deleted element : %d\n", deleteAtPos(pos));
			break;
		case 7:
			display();
			break;
		default:
			break;
		}
	}while(choice!=8);
}
