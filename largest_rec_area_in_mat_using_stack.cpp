class Solution {
  public:
  vector<int> nextElement(vector<int>& arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for(int i=n-1;i>=0;i--)
    {
      int curr=arr[i];
      while(s.top()!=-1 && curr<=arr[s.top()])
      {
        s.pop();
      }
      ans[i]=s.top();
      s.push(i);
    }
    return ans;
}

vector<int> preElement(vector<int>& arr, int n)
{
   stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for(int i=0;i<n;i++)
    {
      int curr=arr[i];
      while(s.top()!=-1 && curr<=arr[s.top()])
      {
        s.pop();
      }
      ans[i]=s.top();
      s.push(i);
    }
    return ans;
}

    int largestRectangleArea(vector<int>& heights,int n) {
        
        vector<int> next(n);
        next=nextElement(heights,n);
        vector<int> pre(n);
        pre=preElement(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            
            if(next[i]==-1)
            {
                next[i]=n;
            }
            int b=next[i]-pre[i]-1;
            int newarea=l*b;
             area=max(area,newarea);
        }
        return area;

        
    }
    // Function to calculate the maximum area of a rectangle
    // in the given matrix.
    int maxArea(vector<vector<int>> &mat) {
        int n=mat[0].size();
        int area=largestRectangleArea(mat[0],n);
        for(int i=1;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]!=0)
                {
                      mat[i][j]=mat[i][j]+mat[i-1][j];
                }
                else
                {
                    mat[i][j]=0;
                }
              
            }
            area=max(area,largestRectangleArea(mat[i],n));
        }
        return area;
        
