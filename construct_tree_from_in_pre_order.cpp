/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  int findposition(vector<int> &inorder,int element,int n)
  {
      for(int i=0;i<n;i++)
      {
          if(inorder[i]==element)
          {
              return i;
          }
      }
      return -1;
  }
  Node* solve(vector<int> &inorder, vector<int> &preorder,int &index,int inOrderStart,int inOrderEnd,int n)
  {
      if(index>=n || inOrderStart>inOrderEnd)
      {
          return NULL;
      }
      
      int element=preorder[index++];
      Node* root=new Node(element);
      int position=findposition(inorder,element,n);
      
      root->left=solve(inorder,preorder,index,inOrderStart,position-1,n);
      root->right=solve(inorder,preorder,index,position+1,inOrderEnd,n);
      return root;
      
  }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n=inorder.size();
        int preOrderIndex=0;
        Node* ans=solve(inorder,preorder,preOrderIndex,0,n-1,n);
        return ans;
        // code here
    }
};
