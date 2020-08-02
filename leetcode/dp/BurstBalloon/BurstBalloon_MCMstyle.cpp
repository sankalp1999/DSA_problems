class Solution {
public:
    
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i + 1 == j)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int cost = 0;
        for(int k = i+1; k < j; k++)
        {
            cost = max(cost, solve(i,k,nums, dp) + solve(k,j, nums, dp) + nums[i]*nums[k]*nums[j]) ;
        }
        return dp[i][j] = cost;
    }
    
    
    int maxCoins(vector<int>& nums) {
        
        int i, j;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        i = 0;
        j = nums.size()-1 ;
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return solve(i, j, nums, dp);
    
        
    }
};
