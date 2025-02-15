Node *solve(Node* root,int &k,int node)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    if(root->data==node)
    {
        return root;
    }
    
    Node* leftans=solve(root->left,k,node);
    Node* rightans=solve(root->right,k,node);
    
    if(leftans!=NULL && rightans==NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;  // make it big so that we dont get again <=0 i.e v r locking our answer
            return root;
        }
        return leftans;
    }
    
     if(leftans==NULL && rightans!=NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
    
}
int kthAncestor(Node *root, int k, int node)
{
   
    Node *ans=solve(root,k,node);
    if(ans==NULL || ans->data==node) //2nd condition if it is first element then no ansestor
    {
        return -1;
    }
    
    else
    {
        return ans->data;
    }// Code here
}
