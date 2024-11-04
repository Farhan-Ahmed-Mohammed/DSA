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

int noOfLeaves(struct Node* head)
{
    if(head==NULL)
    {
       return 0;
    }
   else
   {
    return noOfLeaves(head->left)+noOfLeaves(head->right)+1;
   }

    
}

int main()
{
   struct Node* binaryTree=create(5);;
    binaryTree->left=create(6);
    binaryTree->right=create(7);
    binaryTree->left->left=create(8);
    binaryTree->left->right=create(9);
    binaryTree->right->left=create(10);
    printf("The no of nodes of given binary tree is :%d",noOfLeaves(binaryTree));
}