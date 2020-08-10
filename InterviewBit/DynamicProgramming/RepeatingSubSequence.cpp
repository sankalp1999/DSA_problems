/*
Apply LCS to same string but make sure the comparing letters dont have same index.
So, we want to them match when crossed. Only minor change in if condition.
*/



int Solution::anytwo(string A) {
    
    string B = A;
    int dp[A.size() + 1][A.size() + 1];
    int n = A.size() + 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ;j++)
        {
            dp[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= A.size(); i++)
    {
        for(int j = 1; j <= A.size(); j++)
        {
            if(A[i-1] == B[j-1] && i != j)
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else 
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
  
    return dp[A.size()][A.size()] >= 2;
    
}
