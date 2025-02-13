 class Solution {
  public:
  void solve(Node* root,vector<int> &ans,int level)
  {
      if(root==NULL)
      {
          return ;
      }
      
      if(level==ans.size())
      {
          ans.push_back(root->data);
      }
      
      solve(root->left,ans,level+1); //first insert element at left
      solve(root->right,ans,level+1); //at a level no element at left then move to right
     
  }
    vector<int> leftView(Node *root) {
        
        vector<int> ans;
        solve(root,ans,0);
        return ans;
        // code here
    }
};
