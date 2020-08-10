class Solution {
public:
    int decode(string& s, vector<int>& dp, int i)
    {
        
        if(s[i] == '0')return 0;
        if(i + 1 == s.size())return 1; // When only
        
        if(i == s.size())
        {
            return 1; // 1 way to encode empty string
        }
        if(dp[i]!=-1)return dp[i];
        
        int OneDigit = stoi(s.substr(i,1));
        dp[i] = 0;
        if(OneDigit >= 1)
            dp[i] += decode(s,dp,i+1);
        int TwoDigits = stoi(s.substr(i,2));
        if(TwoDigits >= 10 && TwoDigits <= 26)    
            dp[i] += decode(s,dp,i+2);
        return dp[i];
    }
    
    
    
    int numDecodings(string s) {
        
        vector<int> dp(s.size() + 1, -1);
        int i = 0;
        return decode(s,dp,i);
    }
};


/*
Bottom up from LeetCode discuss
I used a dp array of size n + 1 to save subproblem solutions. dp[0] means an empty string will have one way to decode, dp[1] means the way to decode a string of size 1. I then check one digit and two digit combination and save the results along the way. In the end, dp[n] will be the end result.
*/
public class Solution {
    public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length();
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = s.charAt(0) != '0' ? 1 : 0;
        for (int i = 2; i <= n; i++) {
            int first = Integer.valueOf(s.substring(i - 1, i));
            int second = Integer.valueOf(s.substring(i - 2, i));
            if (first >= 1 && first <= 9) {
               dp[i] += dp[i-1];  
            }
            if (second >= 10 && second <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
}
