/*
Put the queen row by row. 
If valid position, recursively go to the next row.
If found a invalid position, backtrack to previous state and again check in the same row.
If row == n, then generate answer and append.
*/

bool isValid(int row, int col, vector<vector<bool>>& state, int n)
{
    /* we don't need to check the row since we are assuming
    that the current row is still not solved */
    
    /* Also, I don't need to check the rows below the current position 
    since we have not placed any queen below */
    
    /* I had written this earlier. Duplicate work */
    // for(int i = 0; i < n; i++)
    // {
    //     if(state[row][i] == true)
    //     {
    //         return false;
    //     }
    // }
    
    for(int i = 0; i < n; i++)
    {
        if(state[i][col] == true)
        {
            return false;
        }
    }
    // Check diagonals from bottom left to upper right
    int left = row;
    int right =col;
        for(int i=0;i<row;i++){
        for(int j=0;j<n;j++){
            if(state[i][j]==true){
                if(abs(row-i) == abs(col-j)){
                    return false;
                }
            }
        }
    }
    return true;
}


void backtrack(int row, int col, vector<vector<string>>& res, vector<vector<bool>>& state, int n, int& count)
{
    if(row == n )
    {
        count++;
        vector<string> s;

        for(int i = 0; i < n; i++)
        {
            string temp;
            for(int j = 0; j < n; j++)
            {
                if(state[i][j] == true)
                {
                    temp.push_back('Q');
                }
                else
                {
                    temp.push_back('.');
                }
                
            }
            s.push_back(temp);
        }
        res.push_back(s);
        
        return;
    }
    
    /* Earlier, I was running two for loops. Big mistake that led to TLE */ 
    
        for(int j = 0; j < n; j++) 
        {
            if(isValid(row,j,state,n))
            {
                state[row][j] = true;
                backtrack(row+1,col,res,state, n, count);
                state[row][j] = false;
            }
        }
    
    return;
    
}


vector<vector<string> > Solution::solveNQueens(int A) {

    
    vector<vector<string>> res;
    int row = 0;
    int col = 0;
    int count = 0;
    vector<vector<bool>> state(A+1,vector<bool>(A+1, false));
    // row and col < A
    
    backtrack(row,col, res, state, A, count);
    return res;
}
