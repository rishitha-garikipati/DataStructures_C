#include<stdio.h>
#include<ctype.h>
#define size 100
int top=-1;
int a[size];
void push(int ele);
int pop();
int main()
{
	int a,b,res,i=0;
	char ch,postfix[100];
	printf("Enter postfix expression:");
	scanf("%s",postfix);
	while((ch=postfix[i++])!='\0')
	{
		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
			{
				b=pop();
				a=pop();
				switch(ch)
				{
					case '+': res=a+b;
					break;
					case '-': res=a-b;
					break;
					case '*': res=a*b;
					break;
					case '/': res=a/b;
					break;
					case '^': res=a^b;
					break;
				}
				push(res);
			}
	}
	printf("The evaluation is %d",pop());
	return 0;
}
void push(int ele)
{
	a[++top]=ele;
}
int pop()
{
	return (a[top--]);
}
