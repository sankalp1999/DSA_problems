class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        const int n = coins.size();
        vector<int> dp(amount + 1, 0);// DP number of ways to reach a 
                                      // particular amount
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                
                // Dp[i-1][j] is when we don't take ith coin. This happens 
                // for all the cases when coins[j] is more than the amount
                // So, we can take only those amount of ways
                /// Otherwise it dp[i][j - coins[i]]. This means we just need one row and we can ignore rest of the rows.
                // Since anyways dp[i-1][j] is copied as it is.
                if(j >= coins[i])
                {
                    dp[j] += dp[j- coins[i]];
                }
            }
        }

        return dp[amount];
        
        
        
    }
};
