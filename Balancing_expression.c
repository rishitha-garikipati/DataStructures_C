#include<stdio.h>
int top=-1;
char a[100];
void push(char ch);
char pop();
int main()
{
	char infix[100],ch;
	int i=0;
	printf("\n enter expression");
	scanf("%s",infix);
	while((ch=infix[i++])!='\0')
	{
		if(ch=='('||ch=='{'||ch=='[')
		{
			push(ch);
		}
		else if(ch==')'||ch=='}'||ch==']')
		{
			pop();
		}
		else
		{
			break;
		}
		if(top==-1)
		{
			printf("\n given expression is balanced");
		}
		else 
		{
			printf("\n given expression is not balanced");
		}
	}
}
void push(char ch)
{
	a[++top]=ch;
}
char  pop()
{
	return(a[top--]);
}
