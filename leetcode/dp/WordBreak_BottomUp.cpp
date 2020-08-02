class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> dict;
        for(string s : wordDict)
        {
            dict.insert(s);
        }
        dp[0] = true;
        // dp[i] represents is there a string possible(in dict) from ith character
        // dp[i] is true if 0 to i is true
        for(int len = 1; len <= s.size(); len++)
        {
            for(int i = 0; i < len; i++)
            {
                // Check if i to j is true
                if(dp[i] && dict.find(s.substr(i,len-i)) != dict.end() ) 
                {
                    dp[len] = true; 
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
