class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        vector<int> ans;
        int cnt;
        for(int i=0;i<arr.size()-(k-1);i++)
        {
            for(int j=0;j<k;j++)
            {  cnt=0;
                if(arr[i+j]<0)
            {
                cnt=1;
                ans.push_back(arr[i+j]);
                break;
            }
            
            }
            if(cnt!=1)
            {
                ans.push_back(0);
            }
            
        }
        return ans;// write code here
    }
};
