/*
The main idea in this question is to check the start and end using if conditions.
Handle duplicates to save computation.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
      
        vector<vector<int>> res; 
        vector<int> visited(v.size(), 0);
        
        if(v.size() <= 1) return v;
        sort(v.begin(), v.end());
        
        int start = v[0][0];
        int end =   v[0][1];
        
        for(int i = 1; i < v.size(); i++)
        {
            if(i + 1 < v.size() && v[i][0] == v[i+1][0] && v[i][1] == v[i+1][1] )continue;
            { 
                if(end < v[i][0])
                {
                 res.push_back(vector<int>{start, end});
                 start = v[i][0];
                 end = v[i][1];
                }
                if(start == v[i][0] && v[i][1] <= end ) // No need to check this  but to make things clearer
                {
                    continue;
                }
                else if(start==v[i][0] && v[i][1] > end) // No need to check this also
                {
                    end = v[i][1];
                }
                else
                {
                end = max(end,v[i][1]);
                }
                }
        }
        res.push_back(vector<int>{start, end});

        return res;
    }
};
