class Solution {
public:
    unordered_map<string,bool> marker;
    bool helper(string s, unordered_set<string>& dict)
    {
        if(s== "")return true; // empty string means true
        if(dict.find(s) != dict.end())return true;
        if(marker.find(s) != marker.end())return marker[s];
        for(int i = 1; i < s.size(); i++)
        {
            
            // Left hand of the branch and right part of the branch. (If 0 to i is true, check rest of string recursively)
            if(dict.find(s.substr(0, i)) != dict.end() && helper(s.substr(i,s.size() - i), dict))
            {
                marker[s.substr(i, s.size() - i)] = true;
                return true;
            }
        }
        return marker[s] = false;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> dict;
        for(string s : wordDict)
        {
            dict.insert(s);
        }
        return helper(s, dict);
    }
};
