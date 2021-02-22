#include<stdio.h>
#include<stdlib.h>

typedef struct Stack Stack;

struct Stack{
	int data;
	struct Stack *next;
}*top=NULL;



void push(int num){
	Stack *temp;
	temp = (Stack*)malloc(sizeof(Stack));

	if(temp==NULL){
		printf("STACK OVERFLOW\n");
	}else{
		temp->data=num;
		temp->next=top;
		top=temp;
	}
}

int pop(){
	Stack *temp;
	int popedElement;
	if(top==NULL){
		printf("STACK UNDERFLOW\n");
		return -1;
	}else{
		popedElement=top->data;
		temp=top;
		top=top->next;	
	}
	free(temp);
	return popedElement;
}

int size(){
	int count=0;
	Stack *temp=top;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}

void display(){
	Stack *temp=top;
	if(temp==NULL){
		printf("STACK EMPTY\n");
	}else{
		while(temp!=NULL){
			printf("%d\t", temp->data);
			temp=temp->next;
		}	
		printf("\n\n");
	}
}

int main(){
	int choice, num;

	printf("\n\n1. Push\n2. Pop\n3. Size of stack\n4. Display\n5. Exit\n\n");
	do{
		printf("_______________________\n");
		printf("Choice ?= ");
		scanf("%d", &choice);

		switch(choice){
			case 1:{
				printf("Enter element to push : ");
				scanf("%d", &num);
				push(num);
				break;
			}
			case 2:{
				num = pop();
				if(num!=-1){
					printf("Poped element : %d\n", num);
				}
				break;
			}
			case 3:{
				printf("Size of stack : %d\n", size());
				break;
			}
			case 4:{
				display();
				break;
			}
			case 5:{
				printf("THANK YOU\n\n");
				return 0;
			}
			default:
				printf("INVALID input, try again\n");
		}
	}while(choice!=5);
}