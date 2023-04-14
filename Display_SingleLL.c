#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL;
void create();
void insert_beg();
void display();
int main()
{
	int ch;
	printf("1.create\n2.insert_beg\n3.display\n");
	while(1)
	{
		printf("enter ch value");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
			break;
			case 2:insert_beg();
			break;
			case 3:display();
			break;
		}
	}
}
void create()
{
	int value;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter value");
	scanf("%d",&value);
	newnode->data=value;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
}
void insert_beg()
{
	int value;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter value");
	scanf("%d",&value);
	newnode->data=value;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		newnode->next=start;
		start=newnode;
	}
}
void display()
{
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}
}
