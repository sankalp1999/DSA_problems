/*
Dp[i][j] means that whether string is interleaved till i-1 and j- 1 or not.

*/



int Solution::isInterleave(string A, string B, string C) {
    
    
    vector<vector<bool>> dp(A.size() + 1, vector<bool>(B.size() + 1, false));
    
    
    for(int i = 0; i <= A.size(); i++)
    {
        for(int j = 0; j <= B.size(); j++)
        {
            int l = i + j - 1; // Simple math. The length of the interleaved string we are building / checking is i + j - 1
            if(i == 0 && j == 0) // Base case. Null strings are technically interleaved
            {
                dp[i][j] = true;
            }
            else if(j == 0)
            {
                if(C[l] == A[i-1])
                dp[i][j] = dp[i-1][j];
            }
            else if(i == 0  )
            {
                if(C[l] == B[j-1])
                dp[i][j] = dp[i][j-1];
            }
            else 
            {
              
                if(C[l] == A[i-1] && C[l] == B[j-1]) // Both can be true
                {
                    dp[i][j] = dp[i][j-1] | dp[i-1][j]; 
                }
               else if(C[l] == A[i-1]) // I am using A as the vertical word in the table. So, we check  is the string without considering i interleaved or not.
                    dp[i][j] = dp[i-1][j];
                    
               else if(C[l] == B[j-1])
                {
                    dp[i][j] = dp[i][j-1]; // Is string before me interleaved or not?
                }
               else
                   dp[i][j] = false;
            }
        }
    }
    
    
    
    return dp[A.size()][B.size()];
}
