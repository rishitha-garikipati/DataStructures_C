#include <stdio.h>  
#include<stdlib.h>
#define size 5  
int a[size];    
int front = -1, rear = -1;  
void insert_front();
void insert_rear(); 
void delete_front(); 
void delete_rear();
void display();    
int main()    
{
	int opt;
    while(1)
   {
	printf("\n1.Insert at front ");
	printf("\n2.Insert at rear ");
	printf("\n3.Delete from front ");
	printf("\n4.Delete from rear ");
	printf("\n5.Display ");
	printf("\n6.Exit\n");
   }
   printf("\n\nEnter your option ");    
   scanf("%d",&opt);
  switch(opt)
  {
   case 1:    insert_front();
   break;
   case 2:    insert_rear();
   break;
   case 3:    delete_front();
   break;
   case 4:    delete_rear();
   break;
   case 5:    display();
   break;
   case 6: exit(0);
   break;
  }
  return 0;
}
void insert_front()    
{    
     int ele;
    printf("Enter data to insert:");
    scanf("%d",&ele);
 
    if((front==0 && rear==size-1) || (front==rear+1))    
    {    
        printf("Overflow");    
    }    
    else if((front==-1) && (rear==-1))    
    {    
        front=0;
       rear=0;    
        a[front]=ele;    
    }    
    else if((front==0) && (rear<size-1))
    {    
        front=size-1;    
        a[front]=ele;    
    }    
    else    
    {    
        front=front-1;    
        a[front]=ele;    
    }    
}    
    
    
void insert_rear()    
{    
    int ele;
	printf("Enter data to insert:");
	scanf("%d",&ele);
	if((front==0 && rear==size-1) || (front==rear+1))    
    {    
        printf("Overflow");    
    }    
    else if((front==-1) && (rear==-1))    
    {    
        rear=0;    
        a[rear]=ele;    
    }    
    else if((rear==size-1) &&(front>0))    
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
  
void delete_front()    
{    
    if((front==-1) && (rear==-1))    
    {    
        printf("Deque is empty");    
    }    
    else if(front==rear)    
    {    
        printf("\nThe deleted element is %d", a[front]);    
        front=-1;    
        rear=-1;    
    }    
    else if(front==size-1)    
   {    
        printf("\nThe deleted element is %d", a[front]);    
        front=0;    
    }    
    else    
   {    
        printf("\nThe deleted element is %d", a[front]);    
        front=front+1;    
    }    
}    
void delete_rear()    
{    
    if((front==-1) && (rear==-1))    
    {    
        printf("Deque is empty");    
    }    
    else if(front==rear)    
    {    
        printf("\nThe deleted element is %d", a[rear]);    
        front=-1;    
        rear=-1;    
    }    
    else if(rear==0)    
   {    
        printf("\nThe deleted element is %d", a[rear]);    
        rear=size-1;    
    }    
    else    
   {    
        printf("\nThe deleted element is %d", a[rear]);    
        rear=rear-1;    
    }    
}  
void display()    
{    
    int i;  
    i=front; 
    while(i!=rear)    
    {    
        printf("%d\n",a[i]);    
        i=((i+1)%size);
    }    
    printf("%d\n",a[rear]);    
}   

