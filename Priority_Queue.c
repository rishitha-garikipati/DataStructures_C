#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *start=NULL;
void enqueue();
void dequeue();
void display();
int main()
{
    int opt;
    while(1)
    {
        printf("\n1.enq\n2.del\n3.dis\n4.exit");
        printf("\nenter your option");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: exit(0);
           
        }
    }
   
}
void enqueue()
{
    struct node *newnode,*ptr;
    int ele,newpri;
    printf("\nenter element to inesert");
    scanf("%d",&ele);
    printf("\nenter priority of node");
    scanf("%d",&newpri);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->priority=newpri;
    newnode->next=NULL;
    if(start==NULL||newnode->priority>=newpri)
    {
        newnode->next=start;
        start=newnode;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL&& ptr->next->priority<=newpri)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=ptr->next;
 
    }
}
void dequeue()
{
    struct node *ptr=start;
    if(start==NULL)
    printf("Queue is empty");
    else
    {        
        printf("Deleted item is:%d\n",start->data);
        start=start->next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr=start;
    if(start== NULL)  
    printf("Queue is empty\n");  
    else  
    {    
	    while(ptr!=NULL)
        {
            printf("%5d        %5d\n",ptr->priority, ptr->data);
            ptr=ptr->next;
        }
    }
}

   

