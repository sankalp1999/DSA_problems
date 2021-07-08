class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        int p1(0), p2(0), p3(0);
        dp[0]=1;
        for(int i = 1; i < n; i++)
        {
            dp[i] = min({2*dp[p1],3*dp[p2], 5 * dp[p3]}); // Choose in sorted order and avoid duplicates
            if(dp[i] == 2 * dp[p1])p1++;
            if(dp[i] == 3 * dp[p2])p2++;
            if(dp[i] == 5 * dp[p3])p3++;
        }
        return dp[n-1];
    }
};
