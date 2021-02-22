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