//Shellsort using function
#include<stdio.h>
void shellsort(int a[100],int n);
int main()
{
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	shellsort(a,n);
	return 0;
}
void shellsort(int a[100],int n)
{
	int i,j,temp,gap;
	for(gap=n/2;gap>=1;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			for(j=i;j>=gap;j=j-gap)
			{
				if(a[j-gap]>a[j])
				{
					temp=a[j-gap];
					a[j-gap]=a[j];
					a[j]=temp;
				}
			}
		}
		
	}                                        
	for(i=0;i<n;i++)                        
	{                                      
		printf("%d\t",a[i]);               
	}
}
/* To print each step
for(k=0;k<n;k++)
{
   printf("%d  ",a[k]);
}
printf("\n");  */
