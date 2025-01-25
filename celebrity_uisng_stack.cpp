class Solution {
  public:
  bool knows(vector<vector<int> >& mat,int a,int b,int n)
  {
     
          if(mat[a][b]==1)
          {
              return true;
          }
          
          else
          {
              return false;
          }
      
  }
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        stack<int> s;
        int n=mat.size();
        
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        while(s.size()>1)
        {
           int a=s.top();
           s.pop();
           int b=s.top();
           s.pop();
           if(knows(mat,a,b,n))
           {
               s.push(b);
           }
           
           else
           {
               s.push(a);
           }
        }
        int no=s.top();
       
        int zerocnt=0;
        for(int i=0;i<n;i++)
        {
            if(mat[no][i]==0)
            {
                zerocnt++;
            }
        }
        
        if(zerocnt!=n)
        {
            return -1;
        }
        
        
        int oneCnt=0;
        for(int i=0;i<n;i++)
        {
            if(mat[i][no]==1)
            {
                oneCnt++;
                
            }
        }
        
        if(oneCnt!=n-1)
        {
            return -1;
        }
        
        return no;
    }
};
