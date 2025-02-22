#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root,vector<int> &ans)
{
    if(root!=NULL)
    {
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans;
    inorder(root,ans);           //we get in sorted order
    int n=ans.size();

    TreeNode<int>* newRoot=new TreeNode<int>(ans[0]);
    TreeNode<int>* curr=newRoot;
    
    for(int i=1;i<n;i++)      // start from 2nd element
    {
        TreeNode<int>* temp=new TreeNode<int>(ans[i]);
        curr->left=NULL;     //make all left null
        curr->right=temp;    //make curr right as next element in ans 
        curr=temp;
    }
    
    curr->left=NULL;      // for last element both left and right are null
    curr->right=NULL;
    
    return newRoot;// Write your code here
}
