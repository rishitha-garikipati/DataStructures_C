#include <stdio.h>
#include <stdlib.h>
 struct node
{
    int data, ht;
    struct node *left, *right;
};
int max(int a, int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int height(struct node *root)
{
    if(root == NULL)
    return 0;
    else
    return 1+max(height(root->left), height(root->right));
}
struct node *createnode(int data)
{
    struct node *newnode;
    newnode =(struct node*)malloc(sizeof(struct node));
    newnode ->data=data;  
    newnode->ht=0;
    newnode ->left=NULL;  
    newnode ->right=NULL;  
    return newnode;
}
int getbalance(struct node *root)
{
    if(root==NULL)
    return 0;
    return (height(root->left)-height(root->right));
}
struct node * leftrotate(struct node *x)
{
struct node *y = x->right;
struct node *T2=y->left;
y->left=x;
x->right=T2;
x->ht=height(x);
y->ht=height(y);
return y;
}
struct node *rightrotate(struct node *y)
{
struct node *x =y->left;
struct node *T2=x->right;
x->right=y;
y->left=T2;
  x->ht = height(x);
y->ht = height(y);
    // Return new root
    return x;
}
struct node *insert(struct node *root, int data)
{
if (root == NULL)
        return(createnode(data));
if(data < root->data)
   root->left= insert(root->left, data);
else if(data > root->data)
 root->right=insert(root->right, data);
else
return root;
     root->ht = height(root);
         int balance=getbalance(root);
    if(balance>1 && data < root->left->data)       //RR rotation
    return rightrotate(root);    
if(balance<-1 && data > root->right->data)  //LL rotation
    return leftrotate(root);
if(balance>1  &&  data > root->left->data)     //LR rotation
    {
        root->left=leftrotate(root->left);
    return rightrotate(root);
    }
if(balance<-1 && data < root->right->data)     //RL rotation
    {
        root->right=rightrotate(root->right);
    return leftrotate(root);
    }
    return root;
    }
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
  struct node *root = NULL;
  /* Constructing tree given in the above figure */
  root = insert(root, 30);
  root = insert(root, 25);
  root = insert(root, 35);
  root = insert(root, 34);
  root = insert(root, 55);
  root = insert(root, 22);
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);
  return 0;
}
