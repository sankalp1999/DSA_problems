class Solution {
public:
    int numDecodings(string s) {
        
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1; // Ways to decode an empty string
        dp[1] = s[0] == '0' ? 0 : 1; // Check for test case where first digit is 0, things will get clear
        for(int i = 2 ; i < dp.size(); i++)
        {
            int OneDigit = stoi(s.substr(i-1,1) );
            int TwoDigits = stoi(s.substr(i-2,2));
            
            if(OneDigit >= 1 && OneDigit <= 9)
            {
                dp[i] += dp[i-1]; // From previous string, we can add decode in 1 * dp[i-1] ways
                
            }
            if(TwoDigits >= 10 && TwoDigits <=26)
            {
                dp[i] += dp[i-2]; All the possible ways to decode string of length i = ways to reach str(i - 2) + 1 * no. of ways  
            }
        }
        return dp[s.length()];
    }
};
