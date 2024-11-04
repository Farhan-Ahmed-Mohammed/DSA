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



void mirror_image(struct Node* binaryTree)
{
    if(binaryTree==NULL)
    {
       return;
    }
   else
   {
     mirror_image(binaryTree->left);
     mirror_image(binaryTree->right);
    //swap
    struct Node* temp=binaryTree->left;
    binaryTree->left=binaryTree->right;
    binaryTree->right=temp;
   }

    
}

void print_preOrder(struct Node* binaryTree)
{
    if(binaryTree==NULL)
    {
        return;
    }
    printf("%d\n",binaryTree->data);
    print_preOrder(binaryTree->left);
    print_preOrder(binaryTree->right);
}

int main()
{
   struct Node* binaryTree=create(5);;
    binaryTree->left=create(6);
    binaryTree->right=create(7);
    binaryTree->left->left=create(8);
    binaryTree->left->right=create(9);
    binaryTree->right->left=create(10);
     print_preOrder(binaryTree);
    mirror_image(binaryTree);
    printf("The mirror image of given binary tree is :\n");
    print_preOrder(binaryTree);
}