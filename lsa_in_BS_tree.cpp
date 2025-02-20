TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(P->data>root->data && Q->data>root->data)
    {
        return LCAinaBST(root->right,P,Q);
    }

    if(P->data<root->data && Q->data<root->data)
    {
        return LCAinaBST(root->left,P,Q);
    }

    
        return root; // it means one is in lst and other in rst so root is common and least
    
        // Write your code here.
}
