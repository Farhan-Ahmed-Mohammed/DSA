#include <bits/stdc++.h>

bool isSafe(vector<vector<int>>& board,int row,int col,int val)
{
    for(int i=0;i<board[0].size();i++)
    {   // row check
        if(board[row][i]==val)
        {
            return false;
        }
        //col check
        if(board[i][col]==val)
        {
            return false;
        }
        //3x3 matrix check
        if(board[3*(row/3) +i/3][3*(col/3) + i%3]==val)  //dry run this to understand this formula
        {
            return false;
        }


    }
    return true;
}
bool solve(vector<vector<int>>& board)
{
    int n=board[0].size();

    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(board[row][col]==0) // check if empty
            {
                
                for(int val=1;val<=9;val++)
                {
                     if(isSafe(board,row,col,val))
                {
                    board[row][col]=val;
                    bool nextSolution=solve(board);
                    if(nextSolution)
                    {
                        return true;
                    }

                    else
                    {
                        //backTrack
                        board[row][col]=0;

                    }
                }
           
            }
            return false;
        }
    }
}

}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
}
