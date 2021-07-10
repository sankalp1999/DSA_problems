class Solution {
public:
    
    bool solve(string prefix, unordered_set<string>& s, int count, int& flag,vector<int>& dp, int idx)
    {
        if(prefix == "")
        {
            if(count>=2)flag = 1;
            return true;
        }
        if(dp[idx]!=-1)return dp[idx];
        bool a = false;
        for(int i = 1; i <= prefix.size(); i++)
        {
            string temp = prefix.substr(0, i);
            if(s.find(temp) != s.end())
            {
                a = a | solve(prefix.substr(i),s,count+1,flag,dp,idx+i);
            }
        }
        return dp[idx] = a;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_set<string> s;
        for(string p: words)
        {
            s.insert(p);
        }
        vector<string> res;
        int count = 0;
        
        for(int i = 0; i < words.size(); i++)
        {
            int flag = 0;
            vector<int> dp(words[i].size() + 1, -1);
            solve(words[i], s, count, flag,dp,0);
            if(flag)res.push_back(words[i]);
        }
        return res;
    }
};
// for this problem, i will iterate through the words list
// Ofcourse, i will make a unordered_set also for 
// constant time finding of words.
// Then, i will recurse on each word and see if prefix 
// is there in dictionary.
