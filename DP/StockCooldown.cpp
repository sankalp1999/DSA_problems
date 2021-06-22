
// NOTE: HUGE MISTAKE FOUND. Don't pass values or indices in the state.

// Don't pass the prices or the index in the recursive
// call instead what you can do is just subtract it their 
// only because those numbers can be same as the index or the 
// value.




class Solution {
public:
        int dp[5001][2];
    
    int solve(vector<int>& prices, int idx, int buy)
    {
        if(idx >= prices.size())
        {
            return 0;
        }
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        int res = 0;
        if(buy == 0)
        {
        
            res = solve(prices, idx + 1, 1) - prices[idx]; // I buy and move on.
            res = max(res, solve(prices, idx + 1, 0)); // i dont buy and move to next
           
        }
        else 
        {   
       
            res = solve(prices, idx + 1, buy);
            res = max(res, solve(prices, idx + 2, 0) + prices[idx]);
        }
        return dp[idx][buy] = res;
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        int idx = 0;
        memset(dp, -1, sizeof dp);
        return solve(prices, idx,0);
    }
};