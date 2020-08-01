class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        if(nums.empty()) return 0;
        
        vector<int> dp(n + 1 , 1);
        
        for(int i = 0; i < nums.size(); i++) // We check for each element whether it can be added to existing subsequence
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j]) // If nums[i] > nums[j], then that means nums[i] can be added. LIS(i)  = max(LIS(i) , LIS(j) + 1)
                {
                    dp[i] = max(dp[i], dp[j] + 1) ; // 2) Add to subsequence or continue with what have
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
        
    }
};
