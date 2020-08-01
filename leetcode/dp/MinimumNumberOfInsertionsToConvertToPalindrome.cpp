/*
Variation of longest palindromic subsequence
Find LPS. Then n - x is answer. Since, LPS covers all the letters which can already make the palindrome.
So, we need to add rest of the characters once. So, n - x is the answer where x is LPS.
LPS is found using LCS with a reverse of the input string.

Amazing !!!!!!
*/

class Solution {
public:
    int minInsertions(string s) {
        string text1 = s;
        string text2 = text1;
        reverse(text2.begin(), text2.end()); // Just reverse it and find LCS
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
        return s.size() - dp[n][m];
    }
};
