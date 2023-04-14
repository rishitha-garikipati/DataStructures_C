#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*start=NULL;
void create();
void insert_beg();
void insert_middle();
void insert_end();
void delete_beg();
void delete_middle();
void delete_end();
void display();
void sum();
int main()
{
	int ch;
	printf("1.create\n2.insert beg\n3.insert middle\n4.insert end\n5.delete beg\n6.delete middle\n7.delete end\n8.display\n9.sum\n");
	while(1)
	{
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
					break;
			case 2:insert_beg();
					break;
			case 3:insert_middle();
					break;
			case 4:insert_end();
					break;
			case 5:delete_beg();
					break;
			case 6:delete_middle();
					break;
			case 7:delete_end();
					break;
			case 8:display();
					break;
			case 9:sum();
					break;
			case 0:exit(0);
			default:printf("enter valid choice");
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
void insert_end()
{
	int value;
	struct node *newnode,*temp;
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
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void insert_middle()
{
	int value,loc,pos=1;
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter value");
	scanf("%d",&value);
	printf("enter loc");
	scanf("%d",&loc);
	newnode->data=value;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL&&pos!=loc-1)
		{
			pos=pos+1;
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void delete_beg()
{
	struct node *temp;
	if(start==NULL)
	printf("list is empty");
	else
	{
	temp=start;
	start=temp->next;
	free(temp);
    }
}
void delete_end()
{
	struct node *temp,*temp1;
	if(start==NULL)
	printf("list is empty");
	else
	{
	temp=start;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp->next=NULL;
	free(temp1);
	}
}
void delete_middle()
{
	struct node *temp,*temp1;
	int pos=1,loc;
	printf("enter loc to delete");
	scanf("%d",&loc);
	if(start==NULL)
	printf("list is empty");
	else
	{
	temp=start;
	while(temp->next!=NULL&&pos!=loc-1)
	{
		pos=pos+1;	
		temp=temp->next;
	}
	temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
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
void sum()
{
	int sum=0;
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		sum=sum+temp->data;
		temp=temp->next;
	}
	printf("sum=%d",sum);
	
}
