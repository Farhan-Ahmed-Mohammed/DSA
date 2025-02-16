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
  Node* solve(vector<int> &inorder, vector<int> &postorder,int &index,int inOrderStart,int inOrderEnd,int n)
  {
      if(index>=n || inOrderStart>inOrderEnd)
      {
          return NULL;
      }
      
      int element=postorder[(n-1)-(index++)];
      Node* root=new Node(element);
      int position=findposition(inorder,element,n);
      
      root->right=solve(inorder,postorder,index,position+1,inOrderEnd,n);
      root->left=solve(inorder,postorder,index,inOrderStart,position-1,n);
      
      return root;
      
  }

    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        int n=inorder.size();
        int preOrderIndex=0;
        Node* ans=solve(inorder,postorder,preOrderIndex,0,n-1,n);
        return ans;// code here
    }
};
