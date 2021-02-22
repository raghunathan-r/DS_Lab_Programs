#include<stdio.h>
#include<ctype.h>

char stack[30];
int top=-1;

void push(char ch){
	stack[++top]=ch;
}

char pop(){
	return stack[top--];
}

int precedence(char ch){
	if(ch=='^')
		return 3;
	if(ch=='*' || ch=='/')
		return 2;
	if(ch=='+' || ch=='-')
		return 1;
	return 0;
}

int main(){
	char infix[30], postfix[30], ch;
	int i=0, j=0;

	printf("\n\nInfix expression ?= ");
	scanf("%s", infix);

	push(' ');
	while((ch=infix[i++])!='\0'){
		if(ch=='('){
			push(ch);
		}else if(isalnum(ch)){
			postfix[j++]=ch;
		}else if(ch==')'){
			while(stack[top]!='('){
				postfix[j++]=pop();
			}
			pop();
		}else{
			while (precedence(stack[top])>=precedence(ch))
			{
				postfix[j++]=pop();
			}
			push(ch);
		}
	}

	while(stack[top]!=' '){
		postfix[j++]=pop();
	}
	postfix[j]='\0';

	printf("Postfix expression : %s\n", postfix);
	return 0;
}