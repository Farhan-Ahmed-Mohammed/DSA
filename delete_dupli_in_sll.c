#include<stdio.h>
#include<stdlib.h>

struct Node
{
    
    int data;
   struct Node* next;

};

struct Node *insertOrder(int x,struct Node* first)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory not allocated");
        return first;
    }

    newNode->data=x;
    newNode->next=NULL;

    if(first==NULL)
    {
        first=newNode;
        return first;
    }

    if(newNode->data<=first->data)
    {
        newNode->next=first;
        first=newNode;
        return first;
    }

    struct Node *save=first;

    while(save->next!=NULL && save->next->data < newNode->data)
    {
        save=save->next;
    }
    newNode->next=save->next;
    save->next=newNode;
    return first;

}
struct Node* delete(struct Node* first,struct Node* deleteNode)
{
    if(first==NULL)
    {
        printf("Empty list");
        return first;
    }

    if(deleteNode==first)
    {
        first=first->next;
        free(deleteNode);
    }
    struct Node* temp=first;
    struct Node* preNode=NULL;

    while(temp!=NULL && temp!=deleteNode)
    {
        preNode=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("Element not found");
        return first;
    }
    preNode->next=temp->next;
    free(temp);
    return first;
}

struct Node* removedubli(struct Node* first)
{
    if (first == NULL) {
        printf("Empty list\n");
        return first;
    }

    struct Node* temp = first;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            // Found duplicate, remove the next node
            struct Node* duplicate = temp->next;
            temp->next = temp->next->next; // Bypass the duplicate node
            free(duplicate);               // Free the memory of the duplicate
        } else {
            temp = temp->next;  // Move to the next node only if no duplicate
        }
    }

    return first;
}


void print( struct Node *first)
{
    struct Node* temp=first;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

}

int main()
{
    struct Node *first=NULL;
    first=insertOrder(30,first);
    first=insertOrder(25,first);
    first=insertOrder(35,first);
     first=insertOrder(35,first);
    first=insertOrder(35,first);
    first=insertOrder(10,first);
   
    print(first);
    printf("After deleting dublicate :\n");
    first=removedubli(first);
    print(first);
    
   
    
}

