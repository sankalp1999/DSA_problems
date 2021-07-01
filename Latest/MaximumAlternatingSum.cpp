// num stands for the number of numbers in the subsequence. It determines the 
// parity and therefore, it determines whether the number will get added or subtracted.
// After that, the problem is just picking or not picking.
// Also, after that, storing [idx][parity] is enough.
  

// Bottom up solution derived after doing the top down solution.
    long long maxAlternatingSum(vector<int>& nums) {
        int num = 0;
        memset(dp,0,sizeof dp);
        for(int i = 1; i <= nums.size(); i++)
        {
            // either i will include or not 
            // also depends on parity
            for(int j = 0; j < 2; j++)
            {   
                int add = (j % 2) ? -nums[i-1] :nums[i-1];
                dp[i][j] = max(dp[i-1][j], dp[i-1][1-j] + (long long)add);
                // cout << dp[i][j] << " ";
            }
        }
        return max(dp[nums.size()][0], dp[nums.size()][1]);

class Solution {
public:
    
    
    // Idx instead of num was important because 
    // only one parity was associated with one num
    // but for each idx, we have to store the 
    // maximum sum that we can get on it.
    
    long long int dp[100001][2];
    long long int solve(vector<int>&nums, int idx, int num)
    {
        if(idx == nums.size())
            return 0;
        if(dp[idx][num % 2] != -1)
            return dp[idx][num % 2];
        long long int res = 0;
        if(num % 2 == 0) 
        {
            // Two choices
            res = solve(nums, idx + 1, num);
            res = max(res, nums[idx] + solve(nums, idx + 1, num + 1));
        }
        else if(num & 1)
        {
            res = max(res , solve(nums, idx + 1, num));
            res = max(res, -nums[idx] + solve(nums, idx + 1, num + 1));
        }
        // return res;
        return dp[idx][num % 2] = res;
        
    }
    
    
    long long maxAlternatingSum(vector<int>& nums) {
        int num = 0;
        memset(dp,-1,sizeof dp);
        return solve(nums, 0, 0);
        
    }
};
