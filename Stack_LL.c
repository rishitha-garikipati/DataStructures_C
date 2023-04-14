#include<stdio.h>
#include<malloc.h>
void push();
void pop();
void peak();
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
int main()
{
	int ch;
	printf("1.push\n2.pop\n3.peak\n4.display\n");
	while(1)
	{
		printf("\nenter ch value");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:peak();
			break;
			case 4:display();
			break;
		}
	}
}
void push()
{
	struct node *newnode;
	int ele;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter element to be insert");
	scanf("%d",&ele);
	newnode->data=ele;
	if(top==NULL)
	{
		top=newnode;
		newnode->next=NULL;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void pop()
{
    struct node *ptr=top;
    if(top==NULL)
    {
	printf("\n stack is empty");
    }
    else
    {
	printf("\n%d is popped",top->data);
	top=top->next;
	free(ptr);
    }
}
void peak()
{
	if(top==NULL)
	{
		printf("\n stack is empty");
	}
	else
    {
    	printf("\n is top most element in stack",top->data);
	}
}
void display()
{
	struct node *ptr;
	ptr=top;
	while(ptr!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
}
