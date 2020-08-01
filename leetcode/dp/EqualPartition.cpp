class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty())return false;
        long long int sum =0 ;
        for(int i: nums)
        {
            sum += i;
        }
        if(sum % 2 == 1)return false;
        int m = sum/2;
        
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
        dp[0][0] = 1; // Can always take zero. Rest will automatically copy
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(j < nums[i-1]) Till nums[i-1], we have already seen the possible subsets
                {
                    dp[i][j] = dp[i-1][j];
                }
                else 
                {
                    int need = j - nums[i-1]; // We need this much to reach our sum
                    if(dp[i-1][need] == 1 || dp[i-1][j] == 1)// directly above or the subset + this = 1
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        int ans = dp[n][m];
        return ans;
    }
};
