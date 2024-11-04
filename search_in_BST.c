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

void search(struct Node* binaryTree,int key)
{
  
  while(binaryTree != NULL)
  { 
    printf("Visiting :%d\n",binaryTree->data);

     if(key==binaryTree->data)
    {
        printf("Element found\n");
        return;
    } 

    else if(key<binaryTree->data)
    {
        binaryTree=binaryTree->left;
    }

     else
    {
         binaryTree=binaryTree->right;
    }
  }

  printf("Element Not found");
 }


int main()
{
   struct Node* binaryTree=create(15);;
    binaryTree->left=create(4);
    binaryTree->right=create(17);
    binaryTree->left->left=create(3);
    binaryTree->left->right=create(9);
    binaryTree->right->left=create(16);
   search(binaryTree,9);
}