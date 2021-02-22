#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
} *first = NULL;

void insertNode (struct Node *first);
void display (struct Node *first);

int main()
{
	int choice;
	do {
		printf("\n\n1. Insert node\n2. Insert node at index\n3. Delete a node\n4. Display\n5. Search\n6. Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1 : {
				insertNode (first);
				break;
			}
            case 3: {
                break;
            }
			case 4 : {
				display(first);
				break;
			}
			case 6 :
				return 0;
			default :
				printf("Invalid input ! Try again\n\n");
		}
	}while(choice != 6);
}

void insertNode (struct Node *p) {
	struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter the data to insert : ");
	scanf("%d", &(temp->data));
    if (first == NULL) {
        temp->next = NULL;
        first = temp;
    }
    else {
        temp->next = first;
        first = temp;
    }
}

void display (struct Node *first) {
	struct Node *p;
	p = first;
    if (p == NULL) {
        printf("LIST IS EMPTY !\n");
    }
    else {
        while (p != NULL) {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}