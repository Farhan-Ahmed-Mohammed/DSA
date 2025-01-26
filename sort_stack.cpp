#include <bits/stdc++.h> 
void insertSort(stack<int> &stack,int temp)
{
	if(stack.empty() || (!stack.empty() && temp>=stack.top()))
	{
		stack.push(temp);
		return;
	}
	int num=stack.top();
	stack.pop();
	insertSort(stack,temp);
	stack.push(num);
	
}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}
	int temp;
  if (!stack.empty()) {
     temp = stack.top();
    stack.pop();
    sortStack(stack);
  } 
  
  insertSort(stack,temp);// Write your code here
}
