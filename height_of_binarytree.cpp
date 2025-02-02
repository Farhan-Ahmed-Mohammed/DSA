class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {     //constructor
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to find the height of a binary tree.
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
};
