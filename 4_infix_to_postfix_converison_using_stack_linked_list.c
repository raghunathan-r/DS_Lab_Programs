#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	char symbol;
	struct stack *next;
}*top=NULL;

void push(int element){
	struct stack *temp;
	temp=(struct stack*)malloc(sizeof(struct stack));
	temp->symbol = element;
	if(top==NULL){
		temp->next=NULL;
		top=temp;
	}else{
		temp->next=top;
		top=temp;
	}
}

char pop(){
	char popedSymbol;
	struct stack *temp;
	if(top==NULL){
		printf("STACK underflow\n");
		return ' ';
	}else{
		temp=top;
		popedSymbol=temp->symbol;
		top=top->next;
		free(temp);
	}
	return popedSymbol;
}

char peek(){
	return top->symbol;
}

int isEmpty(){
	if(top==NULL){
		return 1;
	}else{
		return 0;
	}
}

int isOperand(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
		return 0;
	}else{
		return 1;
	}
}

int presedence(char ch){
	if(ch=='+' || ch=='-'){
		return 1;
	}else if(ch=='*' || ch=='/'){
		return 2;
	}
	return 0;
}

/*
char* dispStack(){
	char *tempArr = (char*)malloc(11*sizeof(char));
	struct stack *temp=top;
	int i=0;
	if(temp==NULL){
		tempArr[0]=' ';
		tempArr[1]='\0';
		return tempArr;
	}
	while(temp->next!=NULL){
		tempArr[i++]=temp->symbol;
		temp=temp->next;
	}
	return tempArr;
}
*/

char *convert(char *infix){
	char *postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
	int i=0, j=0;
	
	while(infix[i]!='\0'){
		if(isOperand(infix[i])){
			postfix[j++]=infix[i++];
		}else{
			if(presedence(infix[i])>presedence(peek())){
				push(infix[i++]);
			}else{
				postfix[j++]=pop();
			}
		}
	}
	while(top!=NULL){
		postfix[j++]=pop();
	}
	postfix[j]='\0';
	return postfix;
}

int main(){
	char *infix="(a+(b*c))", postfix[10];
	push(' ');
	printf("\nPostfix expression : %s\n", convert(infix));
	return 0;
}