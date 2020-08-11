int Solution::minDistance(string A, string B) {
    
    vector<vector<int>> dp(B.size() + 1, vector<int>(A.size() + 1)); // A -> B is being performed. Draw the table and understand the operations. Dont panic.
    
    dp[0][0] = 0;
    
    for(int i = 1; i < dp.size(); i++)
    {
        dp[i][0] =dp[i-1][0] + 1; // That much insertions are needed anyways.
    }
    for(int i = 1; i < dp[0].size(); i++)
    {
        dp[0][i] =dp[0][i-1] + 1;
    }
    for(int i = 1; i <= B.size(); i++)
    {
        for(int j = 1; j <= A.size(); j++)
        {
            if(A[j-1] == B[i-1] ) // If characters match, we don't need any operation. Just take from previous substring/subproblem.
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else 
            {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1; // Mismatch. If we are at same length, then we do a replace otherwise insertion or deletion
                                                                            // suppose A : a --> B : ab, we need an insertion.dp[i-1][j] + 1 represents that.
                                                                            // If we want a deletion, dp[i][j-1]  + 1 represents that. 
                                                                            // This can be observed while making the table. 
            }
        }
    }
    return dp[B.size()][A.size()];
}
