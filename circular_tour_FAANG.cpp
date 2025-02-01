class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n=gas.size();
       int balance=0;
       int defect=0;    //to strore the negative value
       int start=0;
       for(int i=0;i<n;i++)
       {
           balance+=gas[i]-cost[i];
           if(balance<0)       //if balnce +ve we dont go in and return start
           {
               defect+=balance;    // add defect to balance bcoz it is -ve
               start=i+1;        //start is updated
               balance=0;        // balance start from 0 bcoz from new start
           }
       }
       
       if(defect+balance>=0)
       {
           return start;
       }
       
       else
       {
           return -1;
       }
       // Your code here
    }
