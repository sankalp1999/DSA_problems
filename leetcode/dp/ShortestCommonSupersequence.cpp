/*
First find the lcs.
Get the lcs string.
Then, merge both the strings with one subtraction of lcs.

Finding the LCS helps to ensure that our supersequence will have 
the shortest length.

*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();
        
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
         
        // Obtaining the LCS
        int i = n;
        int j = m;
        string lcs = "";
        while(i > 0 && j > 0)
        {
            if(str1[i-1] == str2[j-1] )
            {
                lcs.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i][j-1] > dp[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
        
        reverse(lcs.begin(), lcs.end()); 
        
        string res = "";
        int k = 0;
        j = 0;
        i = 0;
        
        // Merging the strings by ensuring that lcs is not repeated in the supersequence.
        while(k < lcs.size())
        {
            while(i < str1.size() && str1[i] != lcs[k])
            {
                
                res.push_back(str1[i]); 
                i++;
            }
            i++;
            while(j < str2.size() && str2[j] != lcs[k])
            {
                res.push_back(str2[j]);
                j++;
            }
            j++;
            res.push_back(lcs[k]);
            k++;
        }
        while(i < str1.size())res.push_back(str1[i++]); 
        while(j < str2.size())res.push_back(str2[j++]);
        return res;
    }
};
