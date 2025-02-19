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
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    ans.clear();
    inorder(root);
    
        for(int i=0;i<ans.size();i++)
        {
            if(i+1==k)
            {
                return ans[i];
            }
        }
    

        return -1;
            // Write your code here.
}
