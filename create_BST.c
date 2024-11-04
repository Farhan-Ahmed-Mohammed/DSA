#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct Node* insert(struct Node* binaryTree,int element)
{
    if(binaryTree==NULL)
    {
        return create(element);
    }

    if(element>binaryTree->data)
    {
        binaryTree->right=insert(binaryTree->right,element);
    }

    else
    {
         binaryTree->left=insert(binaryTree->left,element);
    }
    return binaryTree;
}

void inOrder(struct Node* binaryTree)
{
    if(binaryTree!=NULL)
    {
        inOrder(binaryTree->left);
        printf("%d\n",binaryTree->data);
        inOrder(binaryTree->right);
    }
}



int main()
{
   struct Node* binaryTree=NULL;
   binaryTree=insert(binaryTree,15);
   insert(binaryTree,7);
   insert(binaryTree,8);
   insert(binaryTree,9);
   insert(binaryTree,10);
   insert(binaryTree,17);
   inOrder(binaryTree);

   
   
}