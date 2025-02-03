class Solution {
  public:
  pair<int,int> diameterFast(Node* root)
  {
      if(root==NULL)
      {
          pair<int,int> p=make_pair(0,-1);
          return p;
      }
      
      pair<int,int> left=diameterFast(root->left);
      pair<int,int> right=diameterFast(root->right);
      
      int op1=left.first;
      int op2=right.first;
      int op3=left.second+right.second+2;
      
      pair<int,int> ans;
      ans.first=max(op1,max(op2,op3));
      ans.second=max(left.second,right.second)+1;
      return ans;
  }
    int diameter(Node* root) {
        return diameterFast(root).first;// Your code here
    }
};
