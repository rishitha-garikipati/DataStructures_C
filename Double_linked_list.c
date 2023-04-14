#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void create();
void insert_begin();
void insert_middle();
void insert_end();
void delete_begin();
void delete_middle();
void delete_end();
void display();
struct node
{
	int data;
	struct node *prev,*next;
};
struct node *start=NULL;
int main()
{
	int ch;
	while(1)
	{
		printf("\n");
		printf("1.Create\n");
		printf("2.Insert_begin\n");
		printf("3.Insert_middle\n");
		printf("4.Insert_end\n");
		printf("5.Delete_begin\n");
		printf("6.Delete_middle\n");
		printf("7.Delete_end\n");
		printf("8.Display\n");
		printf("9.Exit\n\n");
		printf("Enter your option:");
		scanf("%d",&ch);
		switch(ch)
{
			case 1:
				create();
				break;
			case 2:
				insertatbeg();
				break;
			case 3:
				insertatspec();
				break;
			case 4:
				insertatend();
				break;
			case 5:
				deleteatbeg();
				break;
			case 6:
				deleteatspec();
				break;
			case 7:
				deleteatend();
				break;
			case 8:
				display();
				break;
			case 9:
				exit(0);
		}
	}
return 0;
}
void create()
{
	struct node *newnode,*ptr=start;
	int value;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to be insert:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(start==NULL)
    {
    	start=newnode;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->prev=NULL;
	}
}
void insert_begin()
{
	struct node *newnode;
	int value;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to be insert:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(start==NULL)
    {
    	start=newnode;
	}
	else
	{
		newnode->next=start;
		start->prev=newnode;
		newnode->prev=NULL;
		start=newnode;
	}
}
void insert_middle()
{
	struct node *newnode,*ptr1=start,*ptr2=start;
	int value,loc,i;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to be insert:");
	scanf("%d",&value);
	printf("Enter location of element to be insert:");
	scanf("%d",&loc);
	newnode->data=value;
	newnode->prev=NULL;
    newnode->next=NULL;
	if(start==NULL || loc==0)
	{
		start=newnode;
	}
	else
	{
		for(i=1;i<loc;i++)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
		}
		ptr2->next=newnode;
		ptr1->prev=newnode;
		newnode->next=ptr1;
		newnode->prev=ptr2;
	}
}
void insert_end()
{
	struct node *newnode,*ptr=start;
	int value;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to be insert:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(start==NULL)
    {
    	start=newnode;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->prev=NULL;
    }
}
void delete_begin()
{
	struct node *ptr=start;
	if(start==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		start=ptr->next;
		start->prev=NULL;
		free(ptr);
	}
}
void delete_middle()
{
	struct node *ptr1=start,*ptr2=start;
	int pos,i;
	printf("enter position of element to be delete:");
	scanf("%d",&pos);
	if(start==NULL || pos==0)
	{
		printf("List is empty\n");
	}
	else
	{
		for(i=1;i<pos;i++)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
		}
		ptr2->next=ptr1->next;
		ptr2->next->prev=ptr2;
		free(ptr1);
	}
}
void delete_end()
{
	struct node *ptr1=start,*ptr2=start;
	if(start==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(ptr1->next!=NULL)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
		}
		ptr2->next=NULL;
		free(ptr1);
	}
}
void display()
{
	struct node *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d<->",ptr->data);
		ptr=ptr->next;
	}
}
