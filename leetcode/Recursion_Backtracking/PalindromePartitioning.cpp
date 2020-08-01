class Solution {
public:
    
    bool isPalindrome(string s)
    {
        
        for(int i = 0; i < s.size()/2; i++)
        {
            if(s[i] == s[s.size() - 1- i])continue;
            else return false;
        }
        return true;
    }
    
    void solve(int begin, string& s, vector<vector<string>>& dp, vector<string>& p)
    {
        
        if(begin >= s.size() )
        {
            dp.push_back(p);
            return;
        }
        for(int high = begin; high < s.size(); high++)
        {
            if(isPalindrome(s.substr(begin, high - begin + 1)) ) // We only recurse on strings which are palindrome. Notice, substr
            {
                p.push_back(s.substr(begin, high - begin + 1));
                
                // Explore further. Left part of the string is processed. Recursively process right part.
                solve(high + 1, s, dp, p); // left part has been processed. n - 1 centers so 2^n
                // Backtracking so we unchoose that part
            
                p.pop_back();
            }
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        
        int i, j;
        i = 0;
        j = s.size();
        vector<vector<string>> p;
        vector<string> temp;
        solve(i , s, p, temp);
        return p;
    }
};
