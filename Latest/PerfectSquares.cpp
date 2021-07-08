class Solution {
public:
     int numSquares(int n) {
        vector<int> dp(n + 1, 1e5 + 1);
        dp[0] = 0;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j * j <= n; j++)
            {
                if(i - j * j >= 0)
                {
                    dp[i] = min(dp[i], 1 + dp[i - j * j]);
                }
            }
        }
        return dp[n];
    
    
    
    int solve(vector<int>& nums, int sum, int idx, int n, int dp[][10001])
    {
        if(sum == n)return 0;
        if(idx == nums.size() or sum > n)
            return 111;
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        int res = 0;
        res = 1 + solve(nums,sum+nums[idx],idx,n ,dp);
        
        res = min(res, solve(nums,sum,idx+1,n ,dp));
        return dp[idx][sum] = res;
    }
    
    int numSquares(int n) {
        vector<int> v;
        for(int i = 1; i * i <= n; i++)
        {
            v.push_back(i * i);
        }
        int dp[101][10001];
        memset(dp,-1,sizeof(dp));
        return solve(v, 0, 0, n,dp);
        // Convert this into a coin change problem.
    }
};
