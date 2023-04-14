#include<stdio.h>  
int main()  
{  
    int n,i,h;
    printf("Enter size of the hash table:");
    scanf("%d",&n);
    int key[n], index[n]; 
    printf("Enter keys: ");
    for(i=0; i<n;i++)  
    scanf("%d", &key[i]);      
    for(i = 0; i < n; i ++)  
    {  
        h= (key[i]*key[i]/10) % 10;  
        index[h]=key[i];
    }  
    printf("\nThe indexes of the values in the Hash Table: ");  
    for(i = 0; i < n; i++)  
    {  
        printf("hash[%d]=%d", h,index[i]);  
    }  
    return 0;  
}
