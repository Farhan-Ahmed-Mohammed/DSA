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

struct Node* minValue(struct Node* binaryTree)
{
    while(binaryTree->left!=NULL)
    {
        binaryTree=binaryTree->left;
    }
    return binaryTree;
}

struct Node* delete(struct Node* binaryTree,int x)
{
    if(binaryTree==NULL)
    {
        return NULL;
    }

    if(binaryTree->data==x)
    {
        if( binaryTree->left==NULL && binaryTree->right==NULL) // 0 child case
        {
            free(binaryTree);
            return NULL;
        }
        if( binaryTree->left!=NULL && binaryTree->right==NULL)   // 1 child in left
        {
            struct Node* temp=binaryTree->left; // store in left value in temp
            free(binaryTree);
            return temp;
              
        }

         if( binaryTree->left==NULL && binaryTree->right!=NULL)   // 1 child in right
        {
            struct Node* temp=binaryTree->right; //store right value in temp
            free(binaryTree);
            return temp;
              
        }

         if( binaryTree->left!=NULL && binaryTree->right!=NULL)   // 2 children case
        {
            struct Node* min=minValue(binaryTree->right); //find min from right
            binaryTree->data=min->data;
            binaryTree->right=delete(binaryTree->right,min->data);
            return binaryTree;
        }
        
    }
        

    else if(binaryTree->data>x)
    {
        binaryTree->left=delete( binaryTree->left,x);
    }

    else
    {
        binaryTree->right=delete( binaryTree->right,x);
    }
    return binaryTree;
    
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
   int delElement=10;
   printf("After deleting %d:\n",delElement);
   binaryTree=delete(binaryTree,delElement);
   inOrder(binaryTree);


   
   
}
