#include<stdio.h>
#include<malloc.h>
void enque();
void deque();
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL,*rear=NULL;
int main()
{
	int ch;
	printf("1.enque\n2.deque\n3.display\n");
	while(1)
	{
		printf("enter ch value");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enque();
			break;
			case 2:deque();
			break;
			case 3:display();
			break;
		}
	}
}
void enque()
{
	struct node *newnode;
	int ele;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter element to be insert");
	scanf("%d",&ele);
	newnode->data=ele;
	newnode->next=NULL;
	if(front==NULL&&rear==NULL)
	{
		front=newnode;
	    rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void deque()
{
    struct node *ptr;
    if(front==NULL&&rear==NULL)
    {
	printf("\n queue is empty");
    }
    else
    {
	ptr=front;
	printf("\n%d is deleted",front->data);
	front=front->next;
	free(ptr);
    }
}
void display()
{
	struct node *ptr;
	if(front==NULL&&rear==NULL)
	{
		printf("\n queue is empty");
	}
	else
	{
		ptr=front;
	    while(ptr!=NULL)
	    {
		printf("%d->",ptr->data);
		ptr=ptr->next;
	    }	
	}
}
