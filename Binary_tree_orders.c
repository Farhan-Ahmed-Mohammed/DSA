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

void preOrder(struct Node* head)
{
    
    struct Node* temp=head;
    if(temp!=NULL)
    {
        printf("%d\n",temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void postOrder(struct Node* head)
{
    
    struct Node* temp=head;
    if(temp!=NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d\n",temp->data);
    }
}

void InOrder(struct Node* head)
{
    
    struct Node* temp=head;
    if(temp!=NULL)
    {
        InOrder(temp->left);
        printf("%d\n",temp->data);
        InOrder(temp->right);
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
    printf("The preorder of given numbers is :\n");
    preOrder(binaryTree);
    printf("The Inorder of given numbers is :\n");
    InOrder(binaryTree);
    printf("The Postorder of given numbers is :\n");
    postOrder(binaryTree);


}