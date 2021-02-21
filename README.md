## Pointers

Q 1. Design and implement C program to demonstrate advantages/usage of pointers. (E.g. add two Matrices using pointer concept, Functions for string manipulation, String manipulation functions).

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

Q 2. Design and implement a database application in C. (E.g. Student/Faculty information using structures).

- Array of structures implementation
- Linked list implementation

---

## Stacks

Q 3. Design and implement a stack (Array implementation/ Linked list implementation) and demonstrate its working with necessary inputs. Display the appropriate messages in case of exceptions

- Array implementation
- Linked list implementation

Q 4. Design and implement an algorithm for conversion of an expression from one form to another. Demonstrate its working with suitable inputs.

- Infix to postfix conversion
- Infix to prefix conversion

---

## Linked lists

Q. Design and implement a dynamic list (Singly linked list/ doubly linked list) to store any
information which needs a linear data structure.
