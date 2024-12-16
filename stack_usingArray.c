#include<stdio.h>

int arr[100];
int i=0;
int n=5;
void push(int element)
{
   
    if(i<n)
    {
        arr[i]=element;
        printf("%d is pushed in stack\n",element);
        i++;
    }
}

void pop()
{
    int popElement=arr[i];
    --i;
}

int main()
{
   
    push(5);
    push(10);
    push(15);
    push(20);
    push(25);
    printf("\nThe stack before deleting :\n");
    for(int j=0;j<n;j++)
    {
        printf("%d ",arr[j]);
    }
    pop();
    printf("\nThe stack after deleting :\n");
     for(int j=0;j<i;j++)
    {
        printf("%d ",arr[j]);
    }

}