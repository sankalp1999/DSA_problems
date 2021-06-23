class Solution {
public:
    bool helper(char c, int& prev, vector<vector<int>>& mapper)
    {
        // cout << c << " ";
        if(!mapper[c - 'a'].empty())
        {
            vector<int> temp = mapper[c - 'a'];
             if(prev == 0)
                {
                    prev = temp[0];
                    return true;
                }
            auto upper1 = std::upper_bound(temp.begin(), temp.end(), prev);
            if(upper1 != temp.end())
            {
                int index = upper1 - temp.begin();
                prev = temp[index];
                return true;
            }
        }
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        // unordered_map<char,vector<int>> mapper;
        vector<vector<int>> mapper(26, vector<int>());
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            mapper[c - 'a'].push_back(i); // this will be in sorted order so can upper bound
        }
        int count = 0;
        unordered_map<string,int> word2;
        for(string word : words)
        {
            word2[word]++;
        }
        
        
        for(auto word1 : word2)
        {
            string word = word1.first;
            int occr = word1.second;
            int flag = 0;
            int prev = 0;
            for(int i = 0; i < word.size(); i++)
            {
                if(!helper(word[i],prev,mapper))
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)count+=occr;
        }
        return count;
    }
};
