string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    for(int i=0;i<arr[0].length();i++)//traverseing 1st string
    {
        char ch=arr[0][i];
        bool match=true;
        
        for(int j=1;j<n;j++)//traversing ch with rest of strings
        {
            if(arr[j].size() < i||ch!=arr[j][i])
            {
                match=false;
                break;
            }
        }
        
        if(match==false)
        {
            break;
        }
        
        else
        {
            ans.push_back(ch);
        }
    }
        
        return ans;
      // Write your code here
}


