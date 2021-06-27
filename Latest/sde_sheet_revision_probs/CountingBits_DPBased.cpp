class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> dp(n + 1, 0);
        int num = 1;
        
        
        // dp[1]=1;
        int count = 0;
        // All the n - 1 bits repeat when u cross a certain power.
        for(int i = 1; i <= n; i++)
        {
            if( !(i & (i - 1)) )num=i;
            
            dp[i] = dp[i - num] + 1;
        }
        
        return dp;
    }
};
