#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
}*root=NULL;
struct node *insert(struct node *root,int ele);
void In(struct node *root);
void Pre(struct node *root);
void Post(struct node *root);
void search(struct node *root,int key);
void findmax(struct node *root);
void findmin(struct node *root);
struct node *del(struct node *root,int ele);
struct node *max(struct node *root);
int leafcount(struct node *root);
int main()
{
	int ch,ele,key;
	while(1)
	{
		printf("\n\t1.Insert\n\t2.Inorder\n\t3.Preorder\n\t4.Postorder\n\t5.search\n\t6.findmax\n\t7.findmin\n\t8.delete\n\t9.leafcount\n\t10.exit\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			    printf("Enter an element:");
				scanf("%d",&ele);
				root=insert(root,ele);
				break;
	        case 2:
	        	In(root);
	        	break;
	        case 3:
	        	Pre(root);
	        	break;
	        case 4:
	        	Post(root);
	        	break;
	        case 5:
	        	printf("enter search element");
	        	scanf("%d",&key);
	        	search(root,key);
	        	break;
	        case 6:
	        	findmax(root);
	        	break;
	        case 7:
	        	findmin(root);
	        	break;
	        case 8:
	        	printf("Enter an element to delete:");
				scanf("%d",&ele);
				root=del(root,ele);
				break;
			case 9:
				leafcount(root);
				break;
	        case 10:
	        	exit(0);
	        	break;
	        	
	}
}
}
struct node *insert(struct node *root,int ele)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(root==NULL)
	{
		newnode->data=ele;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	else if(ele>=root->data)
	    root->right=insert(root->right,ele);
	else
	    root->left=insert(root->left,ele);
}
void In(struct node *root)
{
	if(root!=NULL)
	{
		In(root->left);
		printf("%d\t",root->data);
		In(root->right);	
	}
}
void Pre(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		Pre(root->left);
		Pre(root->right);	
	}
}
void Post(struct node *root)
{
	if(root!=NULL)
	{
		Post(root->left);
		Post(root->right);	
		printf("%d\t",root->data);
	}
}
void search(struct node *root,int key)
{
	if(root==NULL)
	{
		printf("\n element doesn't exist in the tree");
	}
	else if(key==root->data)
	{
		printf("\n element is found");
	}
	else if(key>root->data)
	{
		search(root->right,key);
	}
	else if(key<root->data)
	{
		search(root->left,key);
	}
}
void findmax(struct node *root)
{
	if(root==NULL)
	{
	printf("\n not possible to find maximum");
	}
	else if(root->right!=NULL)
	{
		findmax(root->right);
	}
	else
	{
		printf("\n maximum=%d",root->data);
	}
}
void findmin(struct node *root)
{
	if(root==NULL)
	{
	printf("\n not possible to find minimum");
	}
	else if(root->left!=NULL)
	{
		findmin(root->left);
	}
	else
	{
		printf("\n manimum=%d",root->data);
	}
}
struct node *del(struct node *root,int ele)
{
	struct node *ptr;
	if(root==NULL)
	{
		return NULL;
	}
	if(root->left==NULL&&root->right==NULL)
	{
		free(root);
		return NULL;
	}
	if(ele>root->data)
	{
		root->right=del(root->right,ele);
	}
	else if(ele<root->data)
	{
		root->left=del(root->left,ele);
	}
	else
	{
		ptr=max(root);
		root->data=ptr->data;
		root->left=del(root->left,ptr->data);
	}
	return root;
}
struct node *max(struct node *root)
{
	root=root->left;
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}
int leafcount(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(root->left==NULL&&root->right==NULL)
	{
		return 1;
	}
	else
	{
		return leafcount(root->right)+leafcount(root->left);
	}
}

