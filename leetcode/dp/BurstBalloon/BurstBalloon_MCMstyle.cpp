class Solution {
public:
    
    
    int helper(vector<int>& nums, int left, int right, vector<vector<int>>& dp)
    {
        if(left > right)
            return 0;
        if(left + 1 == right)
        {
            return 0;
        }
        
        if(dp[left][right] != -1)
            return dp[left][right];
        
        int ans = 0;
        for(int k = left + 1; k < right; k++)
        {
            ans = max(ans, helper(nums,left,k,dp) + helper(nums,k, right,dp) + nums[left] * nums[k] * nums[right]);
        }
        
        return dp[left][right] = ans;
        
    }
    
    
    
    int maxCoins(vector<int>& nums) {
        
       nums.insert(nums.begin(),1);
       nums.push_back(1);
       vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
       return helper(nums,0,nums.size() - 1,dp);
    }
};
