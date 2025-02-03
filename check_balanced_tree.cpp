class Solution {
   int height(Node* node) {
        if(node==NULL)
        {
            return -1; // here they asked height from 0 index so we took -1 if from 1 index is asked we return 0
        }
        
       
            int left=height(node->left);
            int right=height(node->right);
        
          int ans=max(left,right)+1;
          return ans;
        
        // code here
    }
  public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node* root) {
        if(root==NULL)
        {
            return true;
        }
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        if(left&&right&&diff)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
