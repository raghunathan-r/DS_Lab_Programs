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