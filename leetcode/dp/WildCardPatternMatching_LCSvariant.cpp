class Solution {
public:
    bool isMatch(string s, string p) {
        // If characters match or ? means match, then
        // Check previous substring. If previous substring is true,
        // then only current string can be true, right?
        
        // Since, its a string/substring, if characters are not equal
        // then that means no match.
        
        vector<vector<bool>> dp(s.size() + 1,vector<bool>(p.size() + 1, false));
        dp[0][0] = true; // NULL strings do match
        for(int i = 1; i <= p.size(); i++)
        {
            if(p[i-1] == '*') // *****a is same as *a. 
            {
                dp[0][i] = true; // * at beginning at match later. So, mark true
            }
            else
                break;
        }
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= p.size(); j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                {
                    dp[i][j] = dp[i-1][j-1]; // Check previous substring.
                    // If previous substring is equal, then only later sequence can be true
                }
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    // dp[i][j-1] means * is zero sequence 
                    // Other case is * is taking the sequence.
                }
                else
                    dp[i][j] = false; // Mismatch
            }
        }
        return dp[s.size()][p.size()];
    }
};
