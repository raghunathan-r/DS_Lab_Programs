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

