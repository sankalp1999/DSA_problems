class Solution {

public:
    bool isMatch(string s, string p) {
        // then that means no match.
        
        vector<vector<bool>> dp(s.size() + 1,vector<bool>(p.size() + 1, false));
        dp[0][0] = true; // NULL strings do match
        
        int i = 0;
        while(p[i] == '*')i++;
        p = p.substr(i);
        int count = 0 ;
        for(int i = 1; i <= p.size(); i++)
        {
            count++;
            if(p[i-1] == '*') 
            {
                dp[0][i] = dp[0][i-2];
            }

        }
        
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= p.size(); j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1]; 
                }
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2];
                    if(j-2>=0 && s[i-1] == p[j-2] || p[j-2] == '.')
                    {
                        dp[i][j] = dp[i][j] | dp[i-1][j];
                    }
                }
                else
                    dp[i][j] = false; // Mismatch
            }
        }
        return dp[s.size()][p.size()];
    }
};
