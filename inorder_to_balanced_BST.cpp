void inorder(TreeNode<int>* root,vector<int> &ans)
{
    if(root!=NULL)
    {
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
}
TreeNode<int>* inorderToBst(int s,int e,vector<int> ans)
{
    //base case
    if(s>e)
    {
        return NULL;
    }

    int mid=(s+e)/2;
    TreeNode<int> *root=new TreeNode<int>(ans[mid]);
     root->left=inorderToBst(s,mid-1,ans);
     root->right= inorderToBst(mid+1,e,ans);
     return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> ans;
    inorder(root,ans);
    return inorderToBst(0,ans.size()-1,ans);// Write your code here.
}
