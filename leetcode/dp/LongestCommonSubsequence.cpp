/*
Bottom-up DP utilizes a matrix m where we track LCS sizes for each combination of i and j.

If a[i] == b[j], LCS for i and j would be 1 plus LCS till the i-1 and j-1 indexes.
Otherwise, we will take the largest LCS if we skip a charracter from one of the string (max(m[i - 1][j], m[i][j - 1]).
*/



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1; // smaller strings
                }    
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // delete a char from either strings and see
                }
            }
        }
        return dp[n][m];
    }
};
