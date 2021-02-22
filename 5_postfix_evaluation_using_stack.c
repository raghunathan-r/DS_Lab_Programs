#include<stdio.h>
#include<ctype.h>

struct Stack{
    int S[20];
    int top;
};

typedef struct Stack Stack;

void initStack(Stack *stk){
    stk->top=-1;
}

void push(Stack *stk, int num){
    stk->S[++stk->top]=num;
}

int pop(Stack *stk){
    return stk->S[stk->top--];
}

int postfixEvaluation(char *postfix){
    Stack stk;
    initStack(&stk);
    int x2, x1, result;

    for(int i=0; postfix[i]!='\0'; i++){
        if(isalnum(postfix[i])){
            push(&stk, postfix[i]-'0');
        }else{
            x2=pop(&stk);
            x1=pop(&stk);
            switch(postfix[i]){
                case '+':
                    result=x2+x1;
                    push(&stk, result);
                    break;
                case '-':
                    result=x2-x1;
                    push(&stk, result);
                    break;
                case '*':
                    result=x2*x1;
                    push(&stk, result);
                    break;
                case '/':
                    result=x2/x1;
                    push(&stk, result);
                    break;
            }
        }
    }
    return pop(&stk);
}

int main(){
    char postfix[20];

    printf("\nPostfix expression ?= ");
    scanf("%s", postfix);

    printf("Answer : %d\n", postfixEvaluation(postfix));
    return 0;
}