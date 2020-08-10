int Solution::numDistinct(string A, string B) {
    if(A.size() < B.size())
        return 0;
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp( m + 1, vector<int>(n + 1, 0) );
    
    // Count the occurneces of first character. That is literally equivalent 
    // to single character subsequence.
    for(int i = 1; i <= n ; i++)
    {
        if(A[i-1] == B[0])
        {
            dp[1][i] = dp[1][i-1] + 1; // Count 
        }
        else
            dp[1][i] = dp[1][i-1]; // Number of subsequences till now will still be same so we wont make it zero 
    }
    
    
    for(int i = 2; i <= m; i++)
    {
        for(int j = 1; j <= n; j++ )
        {
            if(A[j-1] == B[i-1])
            {
                dp[i][j] =  dp[i-1][j-1] + dp[i][j-1]; // s[0.... i-1] + char and till now whatever we have
            }
            else
            {
                dp[i][j] = dp[i][j-1]; // Till now
            }
        }
    }   
    
    return dp[m][n];
}
