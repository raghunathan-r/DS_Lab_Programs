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