class Solution {
public:
    
    void solve(string& digits, vector<string>& alpha, int begin,  string& temp, vector<string>& res)
    {
        
        if(begin >= digits.size())
        {
            res.push_back(temp);
            return;
        }
        
        int digit = digits[begin] - '0' ;
        digit -= 2;
        string curr = alpha[digit];
        for(int i = 0; i < curr.size(); i++ )
        {
            temp.push_back(curr[i]);
            solve(digits, alpha, begin + 1, temp, res);
            temp.pop_back();
            
            
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> alpha;
        alpha.push_back("abc");
        alpha.push_back("def");
        alpha.push_back("ghi");
        alpha.push_back("jkl");
        alpha.push_back("mno");
        alpha.push_back("pqrs");
        alpha.push_back("tuv");
        alpha.push_back("wxyz");
        if(digits.empty())return vector<string>{};
        int begin = 0;
        string temp ;
        vector<string> res;
        solve(digits, alpha, begin, temp, res);
        return res;
    }
};
