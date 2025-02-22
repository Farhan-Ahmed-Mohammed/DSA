class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/
vector<int> ans;
void inorder(BinaryTreeNode<int>* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        ans.push_back(root->data);
        inorder(root->right);
    }

    
   
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	  ans.clear();     // clear becoz we have values from b4 test cases so we ahe to clear it every time and now new test cse values are added
     inorder(root);
     int left=0;
     int right=ans.size()-1;

     while(left<right)
     {
         int sum=ans[left]+ans[right];
         if(sum==target)
         {
             return true;
         }

         else if(sum<target)
         {
             left++;
         }

         else{
             right--;
         }
     }
     return false;
    //Write your code here
}
