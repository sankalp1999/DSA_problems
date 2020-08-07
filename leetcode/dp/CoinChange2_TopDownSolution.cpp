/*
Backtracking based solution which has been memoized.
*/

class Solution {
public:
    
   int helper(int amount, vector<int>& coins, int begin, vector<vector<int>>& dp)
    {
       if(begin >= coins.size())return 0;
       
       if(amount < 0)
           return 0;
       
       if(dp[begin][amount] != -1) // Cache
            return dp[begin][amount];
       
       if(amount == 0)
        {
            return 1;
        }
        int ans = 0;
       
        for(int i = begin; i < coins.size(); i++)
        {
            if(amount - coins[i] >= 0)
            {
                int left = helper(amount-coins[i], coins, i, dp); // Can take infinite coins
                int right = helper(amount,coins, i + 1, dp); // Can exclude
                return dp[i][amount] = left + right;   // Memoizing the index is also necessary
            }
        }
        return 0;       
    }
    
    
    
    int change(int amount, vector<int>& coins) {
        
        int count = 0;
        int begin = 0;
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        
        for(int i = 0; i < coins.size(); i++)
        {
            dp[i][0] = 1;
        }
        if(amount == 0)return 1;
        return helper(amount, coins, begin, dp);
    }
};
