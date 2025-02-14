class Solution {
  public:
    void solve(Node* root,int k,int &count,vector<int> ans)
    {
        if(root==NULL)
        {
            return ;
        }
        ans.push_back(root->data);
        
        solve(root->left,k,count,ans);
        solve(root->right,k,count,ans);
        
        int size=ans.size();
        int sum=0;
        for(int i=size-1;i>=0;i--)
        {
            sum+=ans[i];
            if(sum==k)
            {
                count++;
            }
        }
        ans.pop_back();  // pop last eleemnt when going up
    }
  
    int sumK(Node *root, int k) {
       vector<int> ans;
        int count=0;
       solve(root,k,count,ans);
       return count;// code here
    }
};
