#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

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

char *infixToPostfix(char *infix, char *postfix){
    char ch;
    int i=0, j=0;
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
    return postfix;
}

char *reverseString(char *str){
    char *revString;
    revString = (char*)malloc((strlen(str)+1)*sizeof(char));
    int i, j;
    for(i=0, j=strlen(str)-1; i<strlen(str); i++, j--){
        revString[i]=str[j];
    }
    revString[i]='\0';
    return revString;
}

char *infixToPrefix(char *infix, char *postfix){
    // Reverse the infix
    infix=reverseString(infix);

    // Replace '(' with ')' and vise versa
    for(int i=0; i<strlen(infix); i++){
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }

    return reverseString(infixToPostfix(infix, postfix));

}

int main(){
	char infix[30], postfix[30], ch;
	int i=0, j=0;

	printf("\n\nInfix expression ?= ");
	scanf("%s", infix);

	

	printf("Prefix expression : %s\n", infixToPrefix(infix, postfix));
	return 0;
}