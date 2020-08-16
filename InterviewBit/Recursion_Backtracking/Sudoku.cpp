
bool isValid(int i, int j, char check, vector<vector<char>>& A)
{
    int v_offset = i/3; 
    int h_offset = j/3;
    
    
    // grid check
    for(int l = v_offset * 3; l < v_offset * 3 + 3; l++)
    {
        for(int m = h_offset*3; m < h_offset * 3 + 3; m++)
        {
            if(A[l][m] == check)
            {
                return false;
            }
        }
    }
    
    for(int l = 0; l < 9; l++)
    {
        if(A[i][l] == check)
        {
            return false;
        }
    }
    
    // vertical check
    for(int l = 0; l < 9; l++)
    {
        if(A[l][j] == check)
        {
            return false;
        }
    }
    
    return true;
    
}


bool solver(vector<vector<char>>& A, int row, int col)
{
   int n = A.size();
   if(col == A[0].size())
    {
        col = 0;
        row++;
    }
   if(row == 9)
   {
       return true;
   }
   
   if(A[row][col] != '.')
   {
       return solver(A,row,col+1);
   }
   
   for(char c = '1'; c <= '9'; c++)
   {
      if( isValid(row,col,c,A) )
      {
         A[row][col] = c;
         if(solver(A, row, col + 1))
         {
             return true;
         }
         A[row][col] = '.';
      }
   }
   
   // If not able to place, backtrack.
   return false;
   
}

void Solution::solveSudoku(vector<vector<char> > &A) {

    int count = 0;

    solver(A,0,0);
}
