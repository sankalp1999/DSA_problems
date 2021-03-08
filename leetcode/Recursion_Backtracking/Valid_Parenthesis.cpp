// One of the most straightly thinked solutions ever by me!!!!!!!

// How I did this?
// Simply assessed the valid state and how would transition happen 
// or what are the valid choices
class Solution {
public:
    
    void solve(int l, int r, vector<string>& res, string temp, int n)
    {
        if(temp.size() == 2 * n)
        {
            res.push_back(temp);
            return;
        }    
        if(l < n && l >= r)
        {
            solve(l + 1, r, res, temp + "(", n);
        }
        if(r < l)
        {
            solve(l, r + 1, res, temp + ")", n);
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        int l, r;
        l = r = 0;
        solve(l, r, res, temp, n);
        return res;
    }
};