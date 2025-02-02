#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* head=NULL;
struct Node* pre = NULL;


struct Node* insert(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void convertDll(struct Node* root)
{
    

    if(root==NULL)
    {
        return;
    }

    convertDll(root->left);
    if(pre==NULL)    // it means we are at leftmost child in binary tree
    {
        head=root;
    }

    else
    {
        pre->right=root;
        root->left=pre;
    }

    pre=root;

     convertDll(root->right);
}

void printDLL(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->right;
    }
}


int main() {
    // Create a sample binary tree
    struct Node* root = insert(10);
    root->left = insert(5);
    root->right = insert(15);
    root->left->left = insert(2);
    root->left->right = insert(8);
    root->right->left = insert(12);
    root->right->right = insert(20);
    
    // Convert the binary tree to doubly linked list
    convertDll(root);
    
    // Print the doubly linked list
    printf("Doubly Linked List (In-Order): ");
    printDLL(head);
    
    return 0;
}