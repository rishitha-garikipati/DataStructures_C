#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void push(struct Node** head_ref, int data) 
{
    struct Node* new_node = newNode(data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int pop(struct Node** head_ref) 
{
    struct Node* temp = *head_ref;
    int res = temp->data;
    (*head_ref) = (*head_ref)->next;
    free(temp);
    return res;
}
void decimalToBinary(int n) 
{
    struct Node* head = NULL;
    while (n > 0) 
	{
        int rem = n % 2;
        push(&head, rem);
        n /= 2;
    }
    while (head != NULL) 
	{
        printf("%d", pop(&head));
    }
}
int main() 
{
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
	decimalToBinary(n);
	return 0;
}
