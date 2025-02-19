class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr=root;
        while(curr!=NULL)
        {
             if(curr->left)
        {
            Node* prev=curr->left;
            
            while(prev->right)
            {
                prev=prev->right;
            }
            
            prev->right=curr->right;  // connect left sub tree r8 to r8 subtree
            curr->right=curr->left;   // taking node left to right
        }
        
        curr=curr->right;
        }
        
        curr=root;
        while(curr!=NULL)
        {
            curr->left=NULL;  // making all the left null
            curr=curr->right;
        }
       //code here
    }
};
