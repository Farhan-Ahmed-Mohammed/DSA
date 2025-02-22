void inorder(TreeNode* root,vector<int> &a)
{
    if(root!=NULL)
    {
        inorder(root->left,a);
        a.push_back(root->data);
        inorder(root->right,a);
    }
}

 vector<int> merge(vector<int> a1,vector<int> a2) //just like merge sort
 {
     
     int n=a1.size();
     int m=a2.size();
     vector<int> ans(n+m);
     int i=0;
     int j=0;
     int k=0;
     while(i<n && j<m)
     {
         if(a1[i]<a2[j])
         {
             ans[k++]=a1[i];
             i++;
         }

         else
         {
             ans[k++]=a2[j];
             j++;
         }
     }

     while(i<n)
     {
         ans[k++]=a1[i];
         i++;
     }

     while(j<m)
     {
         ans[k++]=a2[j];
         j++;
     }
     return ans;
 }
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> a1,a2;
    inorder(root1,a1);
    inorder(root2,a2);
    return merge(a1,a2);
}

   
    // Write your code here.
