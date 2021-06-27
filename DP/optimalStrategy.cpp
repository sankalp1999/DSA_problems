


/*
We make a choice. Then, our opponent will make such a choice which results us
having the worst choices after he makes a choice.

Our answer is the branch where our choice + opponent 
choice result in the max score.
*/



int solve(int piles[], int i, int j,vector<vector<int>>& dp)
    {
        int n = sizeof(piles)/sizeof piles[0];
        
        if(i > j)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int left = piles[i] + min(solve(piles, i + 2, j ,dp), solve(piles, i + 1, j - 1, dp));
        int right = piles[j] + min(solve(piles, i + 1 , j - 1 ,dp), solve(piles, i , j - 2,dp));
        
        
        dp[i][j] =max(left, right);
        return dp[i][j];
    }   