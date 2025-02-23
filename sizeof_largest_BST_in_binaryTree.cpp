class info
{
    public:
    int mini;  // write in class so that we can access it any where
    int maxi;
    bool isBST;
    int size;
};

info solve(TreeNode* root,int &ans)
{
    if(root==NULL)
    {
        return {INT_MAX,INT_MIN,true,0};
    }

    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
   

    if(left.isBST && right.isBST && (root->data >left.maxi && root->data <right.mini))
    {
        currNode.isBST=true;
    }

    else
    {
        currNode.isBST=false;
    }

    if(currNode.isBST)
    {
        ans=max(ans,currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode* root){
   int maxSize=0; 
   info temp=solve(root,maxSize);
   return maxSize;// Write your code here.
}
