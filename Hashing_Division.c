#include<stdio.h>  
int main()  
{  
    int n, i;
    scanf("%d",&n);
    printf("Enter size of the hash table:");
    int key[n], index[n]; 
    printf("Enter keys: ");
    for(i=0; i<n;i++)  
    scanf("%d", &key[i]);      
    for(i = 0; i < n; i ++)  
    {  
        index[i] = (key[i] % n);  
    }  
    printf("\nThe indexes of the values in the Hash Table: ");  
    for(i = 0; i < n; i++)  
    {  
        printf("%d ", index[i]);  
    }  
    return 0;  
}
