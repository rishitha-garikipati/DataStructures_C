#include <stdio.h>  
#include <stdlib.h>  
#include<malloc.h>
struct node   
{  
    int data;  
    struct node *next;  
}*head, *last;  
   
void createlist(int n);  
void displaylist();  
void insert_at_begin(int data);  
void insert_at_end(int data);  
void insert_at_position(int data, int position);  
void delete_at_position(int position);  
int find_length();  
void find_minimum();  
void find_maximum();  
int search(int data);  
void sort_list();  
int sum_of_elements();
int product_of_elements();
void reverse();
   
int main()  
{  
    int n, data, choice=1;  
   
    while(choice != 0)  
 {  
        printf("---------------------------------------\n");  
        printf("    SINGLE LINKED LIST PROGRAM - MENU    \n");  
        printf("---------------------------------------\n");  
        printf("1. Create a list\n");  
        printf("2. Display The linked list.\n");
        printf("3. Insert node at beginning\n");  
        printf("4. Insert node at end\n");  
        printf("5. Insert node at specified position\n");  
        printf("6. Delete node at specified position\n");  
        printf("7. Find length of the list\n");  
        printf("8. Find minimum element of the list\n");  
        printf("9. Find maximum element of the list\n");  
        printf("10. Search element in the list\n");  
        printf("11. Sort the list\n");  
        printf("12. Find sum of all elements in the list\n");
        printf("13. Find the Product of all elements in the list\n");
        printf("14.Reverse of the elements in the list\n");
        printf("0. Exit\n");  
        printf("--------------------------------------\n");  
        printf("Enter your choice : ");  
        scanf("%d", &choice);  
       
        switch(choice)  
        {  
            case 1:  
                printf("Enter the total number of nodes in list: ");  
                scanf("%d", &n);  
                createlist(n);  
                break;  
            case 2:  
                printf("Enter data of first node: ");  
                scanf("%d", &data);  
                insert_at_begin(data);  
                break;  
            case 3:  
            printf("Enter data of last node: ");  
                scanf("%d", &data);  
                insert_at_end(data);  
                break;  
            case 4:  
                printf("Enter the position where you want to insert new node: ");  
                scanf("%d", &n);  
                printf("Enter data of %d node: ", n);  
                scanf("%d", &data);  
                insert_at_position(data,n);  
                break;  
            case 5:  
                printf("Enter the position of node which you want to delete: ");  
                scanf("%d", &n);  
                delete_at_position(n);  
                break;  
            case 6:  
                n = find_length();  
                printf("Length of the list = %d\n", n);  
                break;  
            case 7:  
                find_minimum();  
                break;  
            case 8:  
                find_maximum();  
                break;  
            case 9:  
                printf("Enter element which you want to search: ");  
                scanf("%d", &data);  
                search(data);  
                break;  
            case 10: 
                    sort_list();  
                break;  
            case 11:  
                n = sum_of_elements();  
                printf("Sum of all elements = %d\n", n);  
                break;   
            case 12:
                displaylist();
                break;
            case 13:
                reverse();
                break;
            case 0:  
                printf("Exiting from application");  
                break;  
            default:  
                printf("Error! Invalid choice. Please choose between 0-11");  
        }  
       
        printf("\n----------------------------------------------------------------------------\n");  
    }  
   
    return 0;  
}  
   
void createlist(int n)  
{  
    struct node *newnode, *temp;  
    int data, i;  
   
    head = (struct node *)malloc(sizeof(struct node));  
   
    if(head == NULL)  
   {  
        printf("Unable to allocate memory.");  
    }  
    else  
    {  
        printf("Enter the data of node 1: ");  
        scanf("%d", &data);  
   
        head->data = data;  
        head->next = NULL;  
        last = head;  
   
        for(i=2; i<=n; i++)  
        {  
            newnode = (struct node *)malloc(sizeof(struct node));  
   
            if(newnode == NULL)  
            {  
                printf("Unable to allocate memory.");  
                break;  
            }  
            else  
            {  
                printf("Enter the data of node %d: ", i);  
                scanf("%d", &data);  
   
                newnode->data = data;  
                newnode->next = NULL;  
   
                last->next = newnode;  
                last = newnode;  
            }  
        }  
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");  
    }  
}  
   
void displaylist()  
{  
    struct node *temp;  
   
    if(head == NULL)  
    {  
        printf("List is empty.");  
    }  
    else  
    {  
        temp = head;  
        while(temp != NULL)  
        {  
            printf("Data = %d\n", temp->data);  
            temp = temp->next;   
        }  
    }  
}  
   
void insert_at_begin(int data)  
{  
    struct node *newnode;  
   
    newnode = (struct node*)malloc(sizeof(struct node));  
   
    if(newnode == NULL)  
    {  
        printf("Unable to allocate memory.");  
    }  
    else  
   {  
        newnode->data = data;  
        newnode->next = head;  
        head = newnode;  
   
        printf("DATA INSERTED SUCCESSFULLY AT BEGINNING OF THE LIST\n");  
    }  
}  
   
void insert_at_end(int data)  
{  
    struct node *newnode;  
   
    newnode = (struct node*)malloc(sizeof(struct node));  
   
    if(newnode == NULL)  
    {  
        printf("Unable to allocate memory.");  
    }  
    else  
    {  
        newnode->data = data;  
        newnode->next = NULL;  
   
        last->next = newnode;  
        last = newnode;  
   
        printf("DATA INSERTED SUCCESSFULLY AT THE END OF THE LIST\n");  
    }  
}  
   
void insert_at_position(int data, int position)  
{  
    int i;  
    struct node *newnode, *temp;  
   
    newnode = (struct node*)malloc(sizeof(struct node));  
   
    if(newnode == NULL)  
    {  
        printf("Unable to allocate memory.");  
    }  
    else  
    {  
        temp = head;  
        for(i=2; i<=position-1; i++)  
        {  
            temp = temp->next;  
   
            if(temp == NULL)  
            break;  
        }  
   
        if(temp != NULL)  
        {  
            newnode->data = data;  
            newnode->next = temp->next;  
            temp->next = newnode;  
   
            printf("DATA INSERTED SUCCESSFULLY AT A SPECIFIED POSITION\n");  
        }  
        else  
       {  
          printf("UNABLE TO INSERT DATA AT THE SPECIFIED POSITION\n");  
        }  
    }  
}  
   
void delete_at_position(int position)  
{  
    int i;  
    struct node *current, *previous;  
   
    current = head;  
    for(i=2; i<=position-1; i++)  
    {  
        previous = current;  
        current = current->next;  
   
        if(current == NULL)  
        break;  
    }  
   
    if(current != NULL)  
    {  
        previous->next = current->next;  
   
        printf("DATA DELETED SUCCESSFULLY FROM A SPECIFIED POSITION\n");  
    }  
    else  
    {  
        printf("UNABLE TO DELETE DATA FROM THE SPECIFIED POSITION\n");  
    }  
}  
   
int find_length()  
{  
    int length = 0;  
    struct node *current;  
   
    current = head;  
   
    while(current != NULL)  
    {  
        length++;  
        current = current->next;  
    }  
   
    return length;  
}  
   
void find_minimum()  
{  
    struct node *current;  
    int min;  
   
    current = head;  
   
    if(head == NULL)  
    {  
        printf("List is empty\n");  
    }  
    else  
    {  
        min = head->data;  
       
        while(current != NULL)  
       {  
            if(min > current->data)  
           {  
                min = current->data;  
            }  
  
            current = current->next;  
        }  
   
        printf("Minimum value in the list = %d\n", min);  
    }  
}  
   
void find_maximum()  
{  
    struct node *current;  
    int max;  
   
    current = head;  
   
    if(head == NULL)  
   {  
        printf("List is empty\n");  
    }  
    else  
    {  
        max = head->data;  
   
        while(current != NULL)  
        {  
            if(max < current->data)  
           {  
                max = current->data;  
            }  
           
            current = current->next;  
        }  
     printf("Maximum value in the list = %d\n", max);  
    }  
}  
   
int search(int data)  
{  
    int position = 0;  
    struct node *current;  
   
    current = head;  
   
    while(current!=NULL)  
    {  
        position++;  
   
        if(current->data == data)  
        {  
            printf("Item %d found at position %d\n", data, position);  
            return position;  
        }  
   
        current = current->next;  
    }  
   
    printf("Item %d not found in list\n", data);  
    return 0;  
}  
   
void sort_list()  
{  
    struct node *current, *index;  
    int temp;  

    if(head == NULL)  
    {  
        printf("List is empty\n");  
    }  
    else  
    {  
        current = head;  
        while(current != NULL)  
        {  
            index = current->next;  
           
            while(index != NULL)  
            {  
                if(current->data > index->data)  
                {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                }  
               
                index = index->next;  
            }  
           
            current = current->next;  
        }  
   
        printf("DATA SORTED IN ASCENDING ORDER\n");  
    }  
}  
int sum_of_elements()  
{  
    struct node *current;  
    int sum = 0;  
   
    current = head;  
   
    while(current != NULL)  
    {  
        sum = sum + current->data;  
      
        current = current->next;  
    }  
   
    return sum;  
}
void reverse(struct node *start)
{
	struct node *ptr=start;
	if(ptr!=NULL)
	{
		reverse(ptr->next);
		printf("%d->,ptr->data");
	}
}
