#include<stdio.h>
#include<stdlib.h>

struct stack{
	int *S;
	int size;
	int top;
};

void initStack(struct stack *stk){
	printf("\n\nMax size of stack ?= ");
	scanf("%d", &stk->size);
	stk->S = (int *)malloc(stk->size * sizeof(int));
	stk->top=-1;
}

void push(int num, struct stack *stk){
	// Check if stack is full
	if(stk->top == stk->size - 1){
		printf("STACK OVERFLOW\n");
		return;
	}else{
		stk->top = stk->top + 1;
		stk->S[stk->top] = num;
	}
}

int pop(struct stack *stk){
	int temp=0;
	temp = stk->S[stk->top];
	stk->top --;
	return temp;
}

void display(struct stack *stk){
	if(stk->top == -1){
		printf("STACK EMPTY\n");
	}else{
		for(int i=stk->top; i>=0; i--){
			printf("%d\t", stk->S[i]);
		}	
		printf("\n\n");
	}
}

int main(){
	int choice, num;
	struct stack stack1;
	initStack(&stack1);

	printf("\n\n1. Push\n2. Pop\n3. Display\n4. Exit\n\n");
	do{
		printf("____________________________________\n");
		printf("Choice ?= ");
		scanf("%d", &choice);

		switch(choice){
			case 1:{
				printf("Enter the element to push : ");
				scanf("%d", &num);
				push(num, &stack1);
				break;
			}
			case 2:{
				num = pop(&stack1);
				if(num){
					printf("Poped element : %d\n", num);
				}else{
					printf("STACK UNDERFLOW\n");
				}
				break;
			}
			case 3:{
				display(&stack1);
				break;
			}
			case 4:{
				printf("THANK YOU\n\n");
				return 0;
			}
			default:
				printf("INVALID input, try again\n");
		}
	}while(choice!=4);
}