class Solution {
public:
    bool isSumTree(Node* root) {
        if (root == NULL) {
            return true;  // An empty tree is a sum tree
        }
        
        if (root->left == NULL && root->right == NULL) {
            return true;  // A leaf node is a sum tree
        }
        
        // Recursively check left and right subtrees and get their sums
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        
        // Check if the current node’s data is equal to the sum of the left and right subtree data
        if (root->data == leftSum + rightSum && isSumTree(root->left) && isSumTree(root->right)) {
            return true;
        }
        
        return false;  // If condition fails, it's not a sum tree
    }
    
    // Helper function to calculate sum of a subtree
    int sum(Node* root) {
        if (root == NULL) {
            return 0;
        }
        
        return root->data + sum(root->left) + sum(root->right);
    }
};
