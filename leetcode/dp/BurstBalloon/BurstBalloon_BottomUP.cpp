class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        int n = nums.size();
        for(int k = 2; k < nums.size(); k++) // Deciding the length of substring
        {
   
            for(int left = 0; left < n - k; left++) // Defining the bounds
            {
                int right = left + k;// left + k == right. If left + 1 == right was the base case in recursive solution
                for(int i = left + 1; i < right; i++)// Mimicking the recursive solution
                {
                    dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + nums[left] * nums[i] * nums[right]);
                }
            }
        }
        return dp[0][nums.size() - 1];
        
        
    }
};
