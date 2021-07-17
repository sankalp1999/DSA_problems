class Solution {
public:
     bool check(string& str, int start, int end)
    {
        int i = start;
        int j = end;
        while(i < j)
        {
            if(str[i] == str[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    

    int solve(int idx, string& str, int n,vector<int>& dp)
    {
        if(idx == n)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int res = INT_MAX;
        for(int i = 1; i <= str.size() - idx ; i++)
        {
            if(check(str, idx, idx + i - 1))
            {
                res = min(res, solve(idx + i, str,n ,dp) );
            }
        }
        return dp[idx] = 1 + res;
    }
    
    int minCut(string s) {
        int idx = 0;
        int n = s.size();
        vector<int> dp(n + 1, -1);
        int res = solve(idx, s, n, dp);
        return res - 1;
    }
};
