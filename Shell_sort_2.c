//Shell sort without function to print every step of sort
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i,j,k,gap,temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
      
    }
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
            for(k=0;k<n;k++)
           {
                printf("%d ",a[k]);
            }
            printf("\n");
        }    
    }
    return 0;
}
