#include <stdio.h>
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
    temp->left=temp->right=NULL;
    return temp;
}

struct Node* insertatTop(struct Node* head,int x)
{
    struct Node* temp=create(x);
    if(temp==NULL)
    {
        printf("Memory not allocated");
        return head;
    }
    
    temp->right=head;
    if(head!=NULL)
    {
        head->left=temp;
    }
    return temp;
}

struct Node* delete(struct Node* head,int x)
{
   
    if(head==NULL)
    {
        printf("The list is empty");
        return head;
    }
    
    if(head->data==x)
    {
        struct Node* temp=head;
        head=head->right;
        free(temp);
        return head;
    }
    
    struct Node* temp=head;
   while (temp != NULL && temp->data != x) {
        temp = temp->right;
    }
    
    if(temp->right==NULL)
    {
        printf("Node not found ");
        return head;
    }
    
    if(temp->left!=NULL)
    {
        temp->left->right=temp->right;
    }
    
    if(temp->right!=NULL)
    {
        temp->right->left=temp->left;
    }
    free(temp);
    return head;
}

void print(struct Node* head)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->right;
    }
}

int main() {
    // Write C code here
   struct Node* head=NULL;
   head=insertatTop(head,5);
   head=insertatTop(head,10);
   head=insertatTop(head,15);
    head=insertatTop(head,20);
  printf("Linked list :\n");
   print(head);
    head=delete(head,15);
    printf("After deleting :\n");
    print(head);

    return 0;
}