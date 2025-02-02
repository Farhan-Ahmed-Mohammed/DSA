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

struct Node *insertOrder2(int x,struct Node* first1)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory not allocated");
        return first1;
    }

    newNode->data=x;
    newNode->next=NULL;

    if(first1==NULL)
    {
        first1=newNode;
        return first1;
    }

    if(newNode->data<=first1->data)
    {
        newNode->next=first1;
        first1=newNode;
        return first1;
    }

    struct Node *save=first1;

    while(save->next!=NULL && save->next->data < newNode->data)
    {
        save=save->next;
    }
    newNode->next=save->next;
    save->next=newNode;
    return first1;

}

struct Node* solve(struct Node* first,struct Node* first1)
{
    if(first->next==NULL)
    {
        first->next=first1;
        return first;
    }
    struct Node* curr1=first;
     struct Node* next1=curr1->next;
      struct Node* curr2=first1;
       struct Node* next2=curr2->next;
       while(next1!=NULL && curr2!=NULL)
       {
        if(curr2->data>=curr1->data && curr2->data<=next1->data)
        {
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;
        }

        else
        {
            curr1=next1;
            next1=next1->next;
            if(next1==NULL)
            {
                curr1->next=curr2;
                return first;
            }

        }
       }
}

struct Node* merge(struct Node* first,struct Node* first1)
{
    if(first==NULL)
    {
        return first1;
    }

    if(first1==NULL)
    {
        return first; 
    }

    if(first->data<=first1->data)
    {
        solve(first,first1);
    }

    else
    {
         solve(first1,first);
    }
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

void print2( struct Node *first1)
{
    struct Node* temp=first1;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

}

int main()
{
    struct Node *first=NULL;
     struct Node *first1=NULL;
    first=insertOrder(30,first);
    first=insertOrder(25,first);
    first=insertOrder(35,first);
    print(first);
    printf("2nd linkedlist :\n");
     first1=insertOrder2(9,first1);
    first1=insertOrder2(4,first1);
    first1=insertOrder2(2,first1);
    print2(first1);
    first=merge(first,first1);
    printf("After merging :\n");
    print(first);
}

