class Solution {
public:
    unordered_map<string,bool> mapper;
    bool solve(string s1, string s2)
    {   
        int n = s1.size();
        // if(s1.size() != s2.size())return false;
        if(s1 == s2)return true;
        if(s1.length() <= 1)return false;
        if( mapper.find(s1+"*"+s2) != mapper.end() )
        {
            return mapper[s1+"*"+s2];
        }
        vector<int> f1(26,0), f2(26, 0);
        for(char ch : s1)
        {
            f1[ch-'a']++;
        }
        for(char ch : s2)
        {
            f2[ch-'a']++;
        }
        if(f1 != f2)
            return mapper[s1 + "*" + s2] =false;
        
        bool res = false;
        for(int i = 1 ; i < n ; i++)
        {
            // No swap case
            string a = s1.substr(0, i);
            string a2 = s2.substr(0, i);
            
            string b = s1.substr(i, n-i);
            string b2 = s2.substr(i, n-i);
            // cout << a << " " << a2 << " " << b << " " << b2 << endl;
            res = res |  (( solve(a,a2) and solve(b,b2) ) or (solve(s1.substr(0,i),s2.substr(n-i,i)) and solve(s1.substr(i,n-i),s2.substr(0,n-i))));  
        }
        return mapper[s1+"*"+s2] = res;
    }
    
    
    
    bool isScramble(string s1, string s2) {
        string a, b;
        a = s1;
        b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i])
                return false;
        }
        
        return solve(s1,s2);
    }
};
