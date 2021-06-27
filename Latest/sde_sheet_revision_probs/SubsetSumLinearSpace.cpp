class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1)
            return false;
        sum = sum / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for(int num : nums)
        {
            for(int j = sum; j >= 0; j--)
            {
                if(num <= j)
                {
                    dp[j] = dp[j - num] | dp[j];
                }
                else dp[j] |= dp[j];
            }
        }
    
        cout << endl;
        return dp[sum];
    }
};
