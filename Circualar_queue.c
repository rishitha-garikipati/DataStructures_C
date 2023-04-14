#include<stdio.h>
#include<stdlib.h>
#define size 5
int front=-1;
int rear=-1;
int a[size];
void enqueue();
void dequeue();
void display();
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.enqueue");
		printf("\n2.dequeue");
		printf("\n3.dispaly");
		printf("\nenter your option");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue;
			break;
			case 2:dequeue;
			break;
			case 3:display;
			break;
		}
	}
	return 0;
}
void enqueue()
{
	int ele;
	printf("\n enter element to insert");
	scanf("%d",&ele);
	if(front==0&&rear==size-1)
	{
		printf("\n queue is full");
	}
	else if(front==-1&&rear==-1)
	{
		rear++;
		front++;
		a[rear]=ele;
	}
	else if(rear==size&&front>0)
	{
		rear=0;
		a[rear]=ele;
	}
	else
	{
		rear++;
		a[rear]=ele;
	}
}
void dequeue()
{
	if(front==-1)
	{
		printf("\n queue is empty");
	}
	else if(front==rear)
	{
		printf("%d",a[front]);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("%d",a[front]);
		front++;
		rear++;
	}
	void display()
	{
		int i;
		if(front>rear)
		{
			for(i=0;i<size;i++)
				{
					printf("%d\t",a[i]);
				}
				for(i=0;i<rear;i++)
				{
					printf("%d\t",a[i]);
				}
		}
		else
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d\t",a[i]);
			}
		}
	}
}
