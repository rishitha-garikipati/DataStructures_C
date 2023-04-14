#include<stdio.h>
#include<malloc.h>
void create();
void insert_beg();
void insert_end();
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
int main()
{
	int ch;
	printf("1.create\n2.insert_beg\n3.insert_end\n4.display\n");
while(1)
{
printf("\nenter ch value");
scanf("%d",&ch);
switch(ch)
{
	case 1:create();
	break;
	case 2:insert_beg();
	break;
	case 3:insert_end();
	break;
	case 4:display();
	break;
}	
}	
}
void create()
{
	int ele;
	struct node *ptr,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter element to the input");
	scanf("%d",&ele);
	newnode->data=ele;
	if(start==NULL)
	{
		start=newnode;
		newnode->next=start;
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=start;
	}
}
void insert_beg()
{
	int ele;
	struct node *ptr,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter element to the input");
	scanf("%d",&ele);
	newnode->data=ele;
	if(start==NULL)
	{
		start=newnode;
		newnode->next=start;
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=start;
		start=newnode;
	}
}
void insert_end()
{
	int ele;
	struct node *ptr,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter element to the input");
	scanf("%d",&ele);
	newnode->data=ele;
	if(start==NULL)
	{
		start=newnode;
		newnode->next=start;
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=start;
	}
}
void display()
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
}
