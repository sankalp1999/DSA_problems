class Solution {
public:
    int solve(vector<int>& nums, int idx, int end, vector<int>& dp)
    {
        if(idx > end)
        {
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int res = 0;
        res = nums[idx] + solve(nums, idx + 2,end,dp);
        res = max(res, solve(nums, idx + 1,end,dp));
        return dp[idx] = res;
    }
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1)return nums[0];
        vector<int> dp(nums.size() + 1, -1);
        int a = solve(nums,0,n - 2,dp);
        fill(dp.begin(), dp.end(),-1);
        int b = solve(nums, 1, n-1 ,dp);
        return max(a,b);
    }
};
