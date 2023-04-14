//Quicksort using function
#include<stdio.h>
void quicksort(int [],int,int);
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
    } 
    quicksort(a,0,n-1);
    printf("\nAfter sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
}
void quicksort(int a[100],int left,int right)
{
	int pivot,i,j,temp;
		i=left;
		j=right;
		pivot=left;
		while(i<j)
		{
			while(a[i]<=a[pivot]&&i<right)
			{
				i++;
			}
			while(a[j]>a[pivot])
			{
				j--;
			}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[pivot];
			a[pivot]=a[j];
			a[j]=temp;
    	}
		quicksort(a,left,j-1);
		quicksort(a,j+1,right);
	}
}
