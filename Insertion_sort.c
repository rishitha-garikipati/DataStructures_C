//Insertion sort using function
#include<stdio.h>
void insertionsort(int a[100],int n);
int main()
{
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertionsort(a,n);
	return 0;
}
void insertionsort(int a[100],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(a[j-1]>a[j])
			{
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
