#include<stdio.h>
#include<stdlib.h>

int size=0;

struct Node{
	int data;
	struct Node *next;
}*head=NULL, *tail=NULL;

typedef struct Node Node;

void insertInBegining(int num){
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=num;

	if(head==NULL){
		temp->next=NULL;
		head=temp;
		tail=temp;
	}else{
		temp->next=head;
		head=temp;
	}
	size++;
}

void insertInEnd(int num){
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=num;

	if(head==tail){
		temp->next=NULL;
		head=temp;
		tail=temp;
	}else{
		temp->next=NULL;
		tail->next=temp;
		tail=temp;
	}
	size++;
}

void display(){
	Node *temp=head;
	while(temp!=NULL){
		printf("%d\t", temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void insertAtPosition(int num, int pos){
	Node *p=head, *q, *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=num;

	if(pos>size+1){
		printf("ERROR invalid position\n");
		return;
	}

	if(pos==1){
		insertInBegining(num);
	}else if(pos==size){
		insertInEnd(num);
	}else{
		for(int i=0; i<pos; i++){
			q=p;
			p=p->next;
		}
		q->next=temp;
		temp->next=p;
	}
	size++;
}

int deleteFromBegining(){
	Node *temp;
	int deletedElement;
	if(head==NULL){
		printf("ERROR list is empty");
		return -1;
	}else{
		temp=head;
		head=head->next;
		deletedElement=temp->data;
	}
	free(temp);
	size--;
	return deletedElement;
}

int deleteFromEnd(){
	Node *temp, *p=head, *q;
	int deletedElement;
	deletedElement=tail->data;
	
	if(tail==NULL){
		printf("ERROR list is empty");
		return -1;
	}else{
		while(p!=NULL){
			q=p;
			p=p->next;
		}
		q->next=NULL;
		tail=q;
		free(p);
	}
	return deletedElement;
}

int main(){
	int choice, num, pos;

	printf("\n\n1. Insert in begginig\n2. Insert at end\n3. Insert at position\n4. Delete in begining\n5. Delete at end\n6. Delete at a position\n7. Display list\n8. Exit\n\n");

	do{
		printf("_______________________\n");
		printf("Enter you choice ?: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Element to insert in begining?= ");
				scanf("%d", &num);
				insertInBegining(num);
				break;
			case 2:
				printf("Element to insert in end?= ");
				scanf("%d", &num);
				insertInEnd(num);
				break;
			case 3:
				printf("Enter the position ?= ");
				scanf("%d", &pos);
				printf("Element to insert in position?= ");
				scanf("%d", &num);
				insertAtPosition(num, pos);
				break;
			case 4:
				if((num=deleteFromBegining())!=-1){
					printf("Deleted element form begining : %d\n", num);
				}
				break;
			case 5:
				if((num=deleteFromEnd())!=-1){
					printf("Deleted element form begining : %d\n", num);
				}
				break;
			case 7:
				display();
				break;
			case 8:
				printf("THANK YOU\n");
				return 0;
			default:
				printf("INVALID input, try again\n");
		}
	}while(choice!=8);
}