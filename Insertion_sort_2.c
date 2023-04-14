//Insertion sort without function by printing each step of the sort
#include<stdio.h>
int main()
{
	int a[100],n;
	printf("Enter n value");
	scanf("%d",&n);
	int i,j,k,temp;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		printf("%d ",a[i]);
		printf("\n");
	}
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
		for(k=0;k<n;k++)
		{
			printf("%d ",a[k]);
		}
		printf("\n");
	}
	return 0;
}
