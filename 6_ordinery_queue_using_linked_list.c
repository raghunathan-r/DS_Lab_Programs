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