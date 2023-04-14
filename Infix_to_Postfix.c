#include<stdio.h>
#include<ctype.h>
#define size 100
int top=-1;
char a[size];
void push(char ch);
char pop();
int priority(char ch);
int main()
{
	char infix[100],postfix[100];
	char ch;
	int i=0,k=0;
	push('#');
	printf("Enter infix expression:");
	scanf("%s",infix);
	while((ch=infix[i++])!='\0')
	{
		if(ch=='(')
		{
			push(ch);
		}	
		else if(ch==')')
	   {
			while(a[top]!='(')
		   {
				postfix[k++]=pop();
			}
		}
		else if(isalnum(ch))
		{
			postfix[k++]=ch;
		}
		else
	   {
		    while(priority(a[top])>=priority(ch))
		   {
			    postfix[k++]=pop();
		    }
		push(ch);
		}
	}
	while(a[top]!='#')
	{
		postfix[k++]=pop();
	}
	postfix[k]='\0';
	printf("The postfix expression is %s",postfix);
	return 0;
}
void push(char ch)
{
	a[++top]=ch;
}
char pop()
{
	return (a[top--]);
}
int priority(char ch)
{
	if(ch=='^')
	return 3;
	else if(ch=='*' || ch=='/')
	return 2;
	else if(ch=='+' || ch=='-')
	return 1;
	else
	return 0;
}
