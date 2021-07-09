class Solution {
public:
    
    
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp)
    {
        
        if(j == t.size() and i <= s.size() )
            return 1;
        if(i == s.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        // t is only going to move if we find an equal character.
        int res = 0;
        if(s[i] == t[j])
        {
            res += solve(s, t, i + 1, j + 1, dp);
            res += solve(s, t, i + 1, j, dp); // I didn't take the character in the hope 
            // that i will find the same character later.
        }
        else
        {
            res += solve(s,t,i+1,j, dp);
        }
        return dp[i][j] = res;
    }
    
    int numDistinct(string s, string t) {
        vector< vector<int> > dp(1001, vector<int>(1001,-1));
        return solve(s, t, 0, 0, dp);
    }
};

// We want the subsequences of s which equals t
// So basic subsequence type recursion should do.
