/*

dp[i][j] : the number of ways to make up amount j by using the first i types of coins
State transition:

not using the ith coin, only using the first i-1 coins to make up amount j, then we have dp[i-1][j] ways.
using the ith coin, since we can use unlimited same coin, we need to know how many ways to make up amount j - coins[i-1] by using first i coins(including ith), which is dp[i][j-coins[i-1]]
Initialization: dp[i][0] = 1

Once you figure out all these, it's easy to write out the code:

    public int change(int amount, int[] coins) {
        int[][] dp = new int[coins.length+1][amount+1];
        dp[0][0] = 1;
        
        for (int i = 1; i <= coins.length; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i-1][j] + (j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0);
            }
        }
        return dp[coins.length][amount];
    }
Now we can see that dp[i][j] only rely on dp[i-1][j] and dp[i][j-coins[i]], then we can optimize the space by only using one-dimension array.

    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
    
*/


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        
        dp[0][0] = 1;
        for(int i = 0; i <= coins.size(); i++)
        {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= coins.size(); i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if(j >= coins[i-1])
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]; // Addition of choices i.e dp[i-1][j] stands for not using ith coin and the 
                                                                   // other one stands for dp[i][j - coins[i-1]] using the ith coin. Its is actually one way 
                                                                   // from dp[i][j-coins[i-1]]
                }else
                {
                    dp[i][j] = dp[i-1][j];                        // We can't include since coin value is more than amount itself. So, include ways 
                                                                  // which we can have without including the ith coin.
                }
            }
        }
        return dp[coins.size()][amount];
    }
};
