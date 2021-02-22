#include<stdio.h>
#include<stdlib.h>
int ele,pos,i,ch;
struct node
{
	int info;
	struct node *prev;
	struct node *next;
};

struct node *head=NULL;

void insertatfront()
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element to be inserted: ");
	scanf("%d",&ele);
	t->info=ele;
	t->prev=NULL;
	t->next=NULL;
	if(head==NULL)
	{
		head=t;
	}
	
	else
	{
		t->next=head;
		head=t;
	}
}

void insertatend()
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	struct node *temp;
	temp=head;
	printf("\nEnter the element to be inserted: ");
	scanf("%d",&ele);
	t->info=ele;
	t->prev=NULL;
	t->next=NULL;
	if(head==NULL)
	{
		head=t;
	}
	
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("\nInsert not possible");
				return;
			}
		}
		
		temp->next=t;
		t->prev=temp;
	}
}

void insertatpos()
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	struct node *temp;
	temp=head;
	printf("\nEnter the position at which element has to be inserted: ");
	scanf("%d",&pos);
	printf("\nEnter the element to be inserted: ");
	scanf("%d",&ele);
	t->info=ele;
	t->prev=NULL;
	t->next=NULL;
	if(head==NULL)
	{
		head=t;
	}
	
	else
	{
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("\nInsert not possible");
				return;
			}
		}
		
		t->next=temp->next;
		t->prev=temp;
		temp->next=t;
		temp->next->prev=t;
		printf("\nElement is inserted");
	}
}

void displayf()
{
	struct node *t;
	t=head;
	printf("\nThe elements are:\n");
	while(t!=NULL)
	{
		printf("%d---",t->info);
		t=t->next;
	}	
}

void deleteatfront()
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nDeleteing isn't possible");
	}
	else
	{
		t=head;
		head=head->next;
		head->prev=NULL;
		printf("\nDeleted element is %d",t->info);
		free(t);
	}
}

void deleteatend()
{
	struct node *t,*s;
	t=head;
	if(head==NULL)
	{
		printf("Deleteing isn't possible");
	}
	else
	{
		while(t->next!=NULL)
		{
			s=t;
			t=t->next;
		}
		
		s->next=NULL;
		printf("\nDeleted element is %d",t->info);
		free(t);
	}
}

void deleteafterele()
{
	struct node *p,*q;
	p=head;
	printf("\nEnter the element after which it has to be deleted: ");
	scanf("%d",&ele);
	while(p->info!=ele)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("\nDeleteing isn't possible");
		}
	}
	q=p->next;
	p->next=q->next;
	q->next->prev=p;
	printf("\nDeleted is deleted");
	free(q);
}

void deleteatpos()
{
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	struct node *t,*p;
	t=head;
	int i=1;
	while(i<pos-1)
	{
		t=t->next;
		i++;
	}
	p=t->next;
	t->next=p->next;
	if(p->next==NULL)
	{
		printf("\nElement is deleted");
		return;
	}
	p->next->prev=t;
	free(p);
	printf("\nElement is deleted");
	
}

void search()
{
	int i=1;
	printf("\nEnter the element to be searched: ");
	scanf("%d",&ele);
	struct node *t;
	t=head;
	while(t->info!=ele)
	{
		i+=1;
		t=t->next;
		if(t==NULL)
		{
			i=-1;
		}
	}
	if(i==-1)
	{
		printf("\nElemet not found");
	}
	else printf("\nFound at position %d",i);
}

void displaye()
{
	struct node *tail;
	// traverse all the way to the end [ may be]
	tail=head;
	while(tail!=NULL){
		tail=tail->next;
	}
	printf("\nThe elements are:\n");
	while(tail!=NULL)
	{
		printf("%d---",tail->info);
		tail=tail->prev;
	}	
}
	

int main()
{
	printf("\n1.Insert at front\n2.Insert at end\n3.Insert at position\n4.Delete at front\n5.Delete at end\n6.Delete after element\n7.Delete at position\n8.Search\n9.Display at front\n10.Display from end\n11.Exit");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insertatfront(); break;
			case 2:insertatend(); break;
			case 3:insertatpos(); break;
			case 4:deleteatfront(); break;
			case 5:deleteatend(); break;
			case 6:deleteafterele(); break;
			case 7:deleteatpos(); break;
			case 8:search(); break;
			case 9:displayf(); break;
			case 10:displaye(); break;
			case 11:exit(0); break;
			default:printf("\nInvalid choice");
		}
	}
}