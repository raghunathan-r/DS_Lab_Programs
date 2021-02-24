# DS Lab Programs

SUBJECT CODE : 18IS33   |  VTU - 3 rd Semester | Information Science and Computer Science 

## Lab Questions list

---

## Pointers

***Q 1. Design and implement C program to demonstrate advantages/usage of pointers. (E.g. add two Matrices using pointer concept, Functions for string manipulation, String manipulation functions).***

- Matrix multiplication

    [How to dynamically allocate a 2D array in C](http://www.firmcodes.com/dynamically-allocate-2d-array-c/)

    Multiplying matrix - [https://www.programiz.com/c-programming/examples/matrix-multiplication](https://www.programiz.com/c-programming/examples/matrix-multiplication)

    Mathematical way - [https://www.youtube.com/watch?v=2spTnAiQg4M](https://www.youtube.com/watch?v=2spTnAiQg4M)

    ```c
    // Design and implement C program to demonstrate advantages/usage of pointers. (E.g. add two Matrices using pointer concept)

    #include <stdio.h>
    #include <stdlib.h>

    struct Matrix{
    	int row;
    	int col;
    	int *M;
    };

    // creating a user defined data type, matrxi for storing all the matrix related information
    typedef struct Matrix matrix;

    // function definations
    matrix initMatrix();
    void displayMatrix (matrix temp);
    void multiplyMatrix (matrix mat1, matrix mat2); 

    // main function
    int main (){
    	
    	matrix mat1, mat2;
    	int ch;
    	printf("\n\n1. Initialise both matrises\n2. Display matrises\n3. Multiply matrises\n4. Exit\n");
    	
    	do{
    		
    		printf("\n____________________________________\n");
    		printf("\nEnter number corresponding to your desired choice : ");
    		scanf("%d", &ch);
    		
    		switch(ch){
    			case 1:
    				// initialiseing both the matrises
    				printf ("\n\nEnter the details for matrix 1 :-");
    				mat1 = initMatrix();
    				printf ("\n\nEnter the details for matrix 2 :-");
    				mat2 = initMatrix();
    				break;
    			
    			case 2:
    				printf("\nDisplying the entered matrix 1 :-\n");
    				displayMatrix (mat1);
    				printf("\nDisplaying the entered matrix 2 :-\n");
    				displayMatrix (mat2);
    				break;
    				
    			case 3:
    				printf("\nDisplaying the product of the two matrises :-\n");
    				multiplyMatrix (mat1, mat2);
    				break;
    			
    			case 4:
    				printf("\nTHANK YOU\n\n");
    				return 0;
    			
    			default :
    				printf("\nINVALID input try again.");
    		}
    		
    		// following three lines is only for pretty output screen
    		printf("\npress a key to continue...");
    		getchar();
    		getchar();
    		//system("clear");
    	}while(ch!=4);
    }

    matrix initMatrix(){
    	matrix temp;
    	printf ("\nEnter the number of row and coloumns :-\n");
    	scanf ("%d %d", &temp.row, &temp.col);
    	temp.M = (int *)malloc((temp.row * temp.col) * sizeof(temp));
    	
    	//printf ("\nEnter the elements of the matrix :-\n");
    	int n=1;
    	for (int i=0; i<temp.row; i++)
    		for (int j=0; j<temp.col; j++)
    			//scanf("%d", (temp.M + i*temp.col + j));
    			*(temp.M + i*temp.col + j) = n++;
    		
    	return temp;
    }

    void displayMatrix(matrix temp){
    	for (int i=0; i<temp.row; i++){
    		for (int j=0; j<temp.col; j++){
    			printf("%d\t", *(temp.M + i*temp.col + j));
    		}
    		printf("\n");
    	}
    }

    void multiplyMatrix(matrix mat1, matrix mat2){
    	matrix prod;
    	// rows are horizontal, coloumsn are vertical
    	// for multiplying a matrix the no. of coloumns in the first matrix must be equal to number of rows in second
    	if (mat1.col != mat2.row){
    		printf("\nERROR the matrix cannot be multiplied.");
    		return;
    	}
    	
    	// the resultant matrix after multiplication will have the following
    	prod.row = mat1.row;
    	prod.col = mat2.col;
    	prod.M = (int*)malloc((prod.row * prod.col) * sizeof(int));
    	// making the product matrix equal to zero
    	for (int i=0; i<prod.row; i++)
    		for(int j=0; j<prod.col; j++)
    			*(prod.M + i*prod.col + j) = 0;
    	
    	// multiplying the matrix
    	for (int i=0; i<mat1.row; i++){
    		for(int j=0; j<mat2.col; j++){
    			for(int k=0; k<mat1.col; k++){
    				*(prod.M + i*prod.col + j) += *(mat1.M + i*mat1.col + k) * *(mat2.M + k*mat2.col + j);
    			}
    		}
    	}
    	
    	displayMatrix(prod);
    }
    ```

- String manipulation

    ```c
    // Design and implement C program to demonstrate advantages/usage of pointers. (E.g. String manipulation functions)

    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    // function definations
    int stringLength (char str[]);
    char* stringConcat(char str1[], char str2[]);
    void stringCopy(char str1[], char str2[]);
    int stringCompare (char str1[], char str2[]);
    char* reverseString (char str1[]);

    // main function
    void main(){
    	int ch;
    	char str1[100], str2[100], copiedStr[100];
    	
    	printf("\n\nEnter the first string :-\n");
    	gets(str1);
    	printf("\nEnter the second sting :-\n");
    	gets(str2);
    	
    	printf("\n\n1. Concatante two strings\n2. Copy the first string\n3. Find the length of the string");
    	printf("\n4. Compare two strings\n5. Reverse a string\n6. Exit\n");
    	do{
    		printf("\n__________________________\n");
    		printf("\nEnter the number corresponding to your desired choice : ");
    		scanf("%d", &ch);
    		
    		switch (ch){
    			case 1:
    				printf("\nThe concatnated string is :-\n");
    				puts(stringConcat(str1, str2));
    				break;
    			
    			case 2:
    				printf("\nCopying string 1 to string 2\n");
    				stringCopy(str1, copiedStr);
    				printf("\nDisplying copiedStr after copying :-\n%s", copiedStr);
    				break;
    				
    			case 3:
    				printf("\nThe length of the first string is : %d", stringLength(str1));
    				break;
    				
    			case 4:
    				if(stringCompare(str1, str2) == 0)
    					printf("\nThe strings are the same.");
    				else
    					printf("\nThe strings are not the same.");
    				break;
    				
    			case 5:
    				printf("\nDisplying the reverse of first string :-\n");
    				printf("%s", reverseString(str1));
    				break;
    				
    			case 6:
    				printf("\nTHANK YOU\n\n");
    				break;
    				
    			default :
    				printf("\nINVALID input, try again.");
    		}
    	}while(ch!=6);
    }

    int stringLength (char str[]){
    	int length;
    	for (length = 0; str[length]!='\0'; length++);
    	return length;
    }

    char* stringConcat(char str1[], char str2[]){
    	int i, len, pos;
    	char *str3;
    	len = stringLength(str1) + stringLength(str2) + 1;
    	str3 = (char*)malloc(len * sizeof(char));
    	
    	// copying the string
    	stringCopy(str1, str3);
    	pos = stringLength(str1);
    	for(int i=0; i <= stringLength(str2); i++){
    		*(str3 + pos) = *(str2 + i);
    		pos ++;
    	}
    	*(str3 + pos + 1) = '\0';
    	return str3;
    }

    void stringCopy(char str1[], char str2[]){
    	int i;
    	for(i=0; i<=stringLength(str1); i++)
    		*(str2 + i) = *(str1 + i);
    	
    	//adding null pointer at the end of the copied string
    	*(str2 + i + 1) = '\0';
    }

    int stringCompare (char str1[], char str2[]){
    	int i = 0, flag = 0;
    	
    	while(*(str1+i) != '\0' && *(str2 + i) != '\0'){
    		if(*(str1 + i) != *(str2 + i)){
    			flag = 1;
    			break;
    		}
    		i++;
    	}
    	return flag;
    }

    char* reverseString(char str1[]){
    	int pos=0, j;
    	char *revStr;
    	revStr = (char*)malloc((stringLength(str1) + 1) * sizeof(char));
    	
    	for(int i=stringLength(str1) - 1, j=0; i>=0; i--, j++){
    		*(revStr + j) = *(str1+i);
    	}
    		
    	*(revStr + j) = '\0';
    	return revStr;
    }
    ```

***Q 2. Design and implement a database application in C. (E.g. Student/Faculty information using structures).***

- Array of structures implementation
- Linked list implementation

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // structure for holding student detail
    struct StudentRecords{
    	char name[100];
    	char usn[10];
    	int marks;
    	struct StudentRecords *next;
    }*head = NULL;

    // user defined data type for student records
    typedef struct StudentRecords student;

    // function definations
    int isEmpty();
    int isFull();
    void addRecord();
    void displayRecord();
    void searchRecord();
    void deleteRecord();

    // main function
    int main(){
    	int ch;
    	
    	
    	printf("\n\n1. Add new student detail\n2. Display all records\n3. Search for detail by USN\n4. Delete student record by USN\n5. Exit\n\n");
    	do{
    		printf("\n__________________________________________________\n");
    		printf("\nEnter the number corresponding to your choice : ");
    		scanf("%d", &ch);
    		
    		switch(ch){
    			case 1:
    				printf("\nEnter the details :-");
    				addRecord();
    				break;
    				
    			case 2:
    				displayRecord();
    				break;
    				
    			case 3:
    				searchRecord();
    				break;
    				
    			case 4:
    				deleteRecord();
    				break;
    			
    			case 5:
    				printf("\n\nTHANK YOU\n\n");
    				return 0;
    			
    			default:
    				printf("\nINVALID input, try again.");
    		}
    	}while(ch != 5);
    }

    int isEmpty(){
    	// 0 is false 1 is true
    	if(head == NULL)
    		return 1;
    	else
    		return 0;
    }

    int isFull(){
    	student *temp = (student *)malloc(sizeof(student));
    	if(temp == NULL)
    		return 1;
    	else
    		return 0;
    }

    void addRecord (){
    	student *temp = (student *)malloc(sizeof(student));
    	if(temp == NULL){
    		printf("\nERROR the memory is full.");
    		return;
    	}
    	
    	// entering the details
    	getchar();
    	printf("\n Name : ");
    	gets(temp->name);
    	printf("\n USN : ");
    	scanf("%s", temp->usn);
    	printf("\n Marks : ");
    	scanf("%d", &temp->marks);
    	
    	if(isEmpty()==1){
    		temp->next == NULL;
    		head = temp;
    	}
    	else{
    		temp->next = head;
    		head = temp;
    	}
    }

    void displayRecord(){
    	student *temp = head;
    	printf("\nDisplaying the records :-\n");
    	while(temp != NULL){
    		printf("\nName : %s\nUSN : %s\nMarks : %d\n\n", temp->name, temp->usn, temp->marks);
    		temp = temp->next;
    	}
    }

    void searchRecord(){
    	char usn[10];
    	int flag = 0;
    	student *temp = head;
    	printf("\nEnter the USN to search for : ");
    	scanf("%s", usn);
    	
    	while(temp != NULL){
    		if(strcmp(usn, temp->usn) == 0){
    				printf("\nFOUND record.\n");
    				printf("\nName : %s\nUSN : %s\nMarks : %d\n\n", temp->name, temp->usn, temp->marks);
    				flag = 1;
    				return;
    		}
    		temp = temp->next;
    	}
    	
    	if(flag == 0)
    		printf("\nERROR record not found.");
    }

    void deleteRecord(){
    	char usn[10];
    	int flag = 0;
    	student *temp = head, *prev;
    	printf("\nEnter the USN to delete : ");
    	scanf("%s", usn);
    	
    	// If node to be delted is head node
    	if(temp!=NULL && strcmp(temp->usn, usn)==0){
    		head = temp->next;
    		free(temp);
    		flag=1;
    	}else{
    		while(temp!=NULL && strcmp(temp->usn, usn)==0){
    			prev=temp;
    			temp=temp->next;
    		}
    		// If element is not found
    		if(temp==NULL){
    			printf("ERROR record not found\n");
    		}
    		// Elese linking to next node
    		prev->next = temp->next;
    		free(temp);
    	}
    }
    ```

---

## Stacks

***Q 3. Design and implement a stack (Array implementation/ Linked list implementation) and demonstrate its working with necessary inputs. Display the appropriate messages in case of exceptions***

- Array implementation

    ```c
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
    ```

- Linked list implementation

    ```c
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
    ```

***Q 4. Design and implement an algorithm for conversion of an expression from one form to another. Demonstrate its working with suitable inputs.***

- Infix to postfix conversion

    [Infix to Postfix | Expression evaluation | Appliedcourse](https://www.youtube.com/watch?v=rUC2Rffejj8)

    [Infix to postfix conversion program in C using stack (With algorithm)](https://qawithexperts.com/article/c-cpp/infix-to-postfix-conversion-program-in-c-using-stack-with-al/156)

    ```c
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
    ```

- Infix to prefix conversion

    [Convert Infix To Prefix Notation - GeeksforGeeks](https://www.geeksforgeeks.org/convert-infix-prefix-notation/)

    [https://www.youtube.com/watch?v=8QxlrRws9OI](https://www.youtube.com/watch?v=8QxlrRws9OI)

    ```c
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
    ```

***Q 5. Design and implement an algorithm to evaluate an arithmetic expressions which may be any form (postfix, prefix, infix), and demonstrate its working with suitable examples.***

- Postfix evaluation

    ```c
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
    ```

- Prefix evaluation
- [ ]  ⚠️Do prefix evaluation

---

## Queues

***Q 6. Design and implement a given type of (ordinary queue, circular queue) queue in C (array implementation/ Linked list implementation). And demonstrate its working with suitable inputs. Display appropriate messages in case of exceptions.***

- Ordinary queue array implementation

    ```c
    #include<stdio.h>
    #include<stdlib.h>

    struct Queue
    {
        int size;
        int front;
        int rear;
        int *Q;
    };

    void createQueue (struct Queue *q);
    void enqueue (struct Queue *q, int num);
    int dequeue (struct Queue *q);
    void display(struct Queue q);

    int main()
    {
        int ch;
        struct Queue q;
        createQueue(&q);
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
                        enqueue(&q, num);
                        break;
                    }
                case 2:
                    {
                        printf("The deleted element is : %d\n", dequeue(&q));
                        break;
                    }
                case 3:
                    {
                        display(q);
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

    void createQueue (struct Queue *q)
    {
        printf("\nEnter the size of the queue : ");
        scanf("%d", &(q->size));
        q->Q = (int *)malloc(q->size * sizeof(int));
        q->front = -1;
        q->rear = -1;    
    }

    void enqueue (struct Queue *q, int num)
    {
        if(q->rear == q->size - 1)
        {
            printf("Queue is FULL\n");
        }
        else
        {
            q->rear = q->rear + 1;
            q->Q[q->rear] = num;    
        }
    }

    int dequeue (struct Queue *q)
    {
        int deletedElement = -1;
        if (q->front == q->rear)
        {
            printf("Queue is EMPTY\n");
        }
        else
        {
            q->front = q->front + 1;
            deletedElement = q->Q[q->front];
        }
        return deletedElement;
    }

    void display(struct Queue q)
    {
        printf("Displaying the elements in the queue :-\n");
        for (int i = q.front + 1; i <= q.rear; i++)
        {
            printf("%d\t", q.Q[i]);
        }
        printf("\n");
    }
    ```

- Ordinary queue linked list implementation

    ```c
    #include<stdio.h>
    #include<stdlib.h>

    struct Node
    {
        int data;
        struct Node *next;
    }*front = NULL, *rear = NULL;

    void enqueue(int num);
    int dequeue ();
    void display ();

    int main()
    {
        int ch, num;
        printf("\n1. Add element\n2. Delete element\n3. Display queue\n4. Exit\n");
        do
        {
            printf("\nEnter the element correspoding to your desiered choice : ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("Enter the element to be added : ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                printf("The deleted element is : %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("THANK YOU :)\n");
                return 0;
            default:
                printf("INVALID INPUT TRY AGAIN\n");
                break;
            }
        } while (ch != 4);
    }

    void enqueue(int num)
    {
        struct Node *temp;
        temp = (struct Node *)malloc(sizeof(struct Node));

        if (temp == NULL)
        {
            printf("Queue is FULL\n");
        }
        else
        {
            temp->data = num;
            temp->next = NULL;
            if (front == NULL)
            {
                front = rear = temp;
            }
            else
            {
                rear->next = temp;
                rear = temp;
            }
        }
    }

    int dequeue ()
    {
        int elementDeleted;
        struct Node *temp;
        
        if (front == NULL)
        {
            printf("Queue is EMPTY\n");
            return -1;
        }
        else
        {
            elementDeleted = front->data;
            temp = front;
            front = front->next;
            free(temp);
        }
        return elementDeleted;
    }

    void display ()
    {
        struct Node *p = front;
        printf("Displaying the elements of the queue :-\n");
        while(p != NULL)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
    ```

- Circular queue using array

    ```c
    #include<stdio.h>
    #include<stdlib.h>

    struct Queue
    {
        int size;
        int front;
        int rear;
        int *Q;
    };

    void createQueue (struct Queue *q);
    void enqueue (struct Queue *q, int num);
    int dequeue (struct Queue *q);
    void display(struct Queue q);

    int main()
    {
        int ch;
        struct Queue q;
        createQueue(&q);
        printf("\n1. Add element\n2. Delete element\n3. Display queue\n4. Exit\n\n");
        
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
                        enqueue(&q, num);
                        break;
                    }
                case 2:
                    {
                        printf("The deleted element is : %d\n", dequeue(&q));
                        break;
                    }
                case 3:
                    {
                        display(q);
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

    void createQueue (struct Queue *q)
    {
        printf("\nEnter the size of the queue : ");
        scanf("%d", &(q->size));
        // As in circular queue the front index element will alwyas be zero we increase the size by 1 
        q->size = q->size + 1;
        q->Q = (int *)malloc(q->size * sizeof(int));
        q->front = q->rear = 0;    
    }

    void enqueue (struct Queue *q, int num)
    {
        if((q->rear + 1) % q->size == q->front)
        {
            printf("Queue is FULL\n");
        }
        else
        {
            q->rear = (q->rear + 1) % q->size;
            q->Q[q->rear] = num;    
        }
    }

    int dequeue (struct Queue *q)
    {
        int deletedElement = -1;
        if (q->front == q->rear)
        {
            printf("Queue is EMPTY\n");
        }
        else
        {
            q->front = (q->front + 1) % q->size;
            deletedElement = q->Q[q->front];
        }
        return deletedElement;
    }

    void display(struct Queue q)
    {
        printf("Displaying the elements in the queue :-\n");
        int i = q.front + 1;
        do
        {
            printf("%d\t", q.Q[i]);
            i = (i + 1) % q.size;
        } while (i != (q.rear + 1) % q.size);
        printf("\n");
    }
    ```

- Circular queue using linked list

    ```c
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
    ```

---

## Linked lists

***Q 7. Design and implement a dynamic list (Singly linked list/ doubly linked list) to store any
information which needs a linear data structure.***

- Singly linked list

    ```c
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
    ```

- Doubly linked list

    ```c
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
    ```

---

## Binary trees

***Q 8. Design and implement binary tree and demonstrate its working.***

- Code

    ```c
    #include<stdio.h>
    #include<stdlib.h>

    struct Node{
        int info;
        struct Node *left;
        struct Node *right;
    };

    typedef struct Node Node;

    Node* maketree(){
        Node *p;
        int info;

        printf("Enter info [-1 for NULL] : ");
        scanf("%d", &info);
        if(info==-1)
            return NULL;
        
        p=(Node*)malloc(sizeof(Node));
        p->info=info;
        printf("Enter the left child of %d\n", info);
        p->left=maketree();
        printf("Enter the right child of %d\n", info);
        p->right=maketree();

        return p;
    }

    void preorder(Node *p){
        if(p!=NULL){
            printf("%d-> ", p->info);
            preorder(p->left);
            preorder(p->right);
        }   
    }

    void postorder(Node *p){
        if(p!=NULL){
            preorder(p->left);
            preorder(p->right);
            printf("%d-> ", p->info);
        }
    }

    void inorder(Node *p){
        if(p!=NULL){
            inorder(p->left);
            printf("%d=> ", p->info);
            inorder(p->right);
        }
    }

    int main(){
        Node *root;
        root=maketree();

        printf("Preorder :-\n");
        preorder(root);
        printf("\n\nPostorder :-\n");
        postorder(root);
        printf("\n\nInorder :-\n");
        inorder(root);

        return 0;
    }
    ```

---

Thank you for looking into this repository 🙏 Glad [**I**](https://twitter.com/raghunathan__r) could be of some help 😊
