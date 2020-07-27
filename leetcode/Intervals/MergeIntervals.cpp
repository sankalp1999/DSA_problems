/*
The main idea in this question is to check the start and end using if conditions.
Handle duplicates to save computation.


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
      
        vector<vector<int>> res; 
        vector<int> visited(v.size(), 0);
        
        if(v.size() <= 1) return v;
        sort(v.begin(), v.end()); // Using  a set here gives better runtime as it handles duplicates and sorts also.
        
        int start = v[0][0];
        int end =   v[0][1];
        
        for(int i = 1; i < v.size(); i++)
        {
            if(i + 1 < v.size() && v[i][0] == v[i+1][0] && v[i][1] == v[i+1][1] )continue;
            { 
                if(end < v[i][0]) // If our current end is less than start of next, then time change start and push the current result.
                {
                 res.push_back(vector<int>{start, end});
                 start = v[i][0];
                }
                if(start == v[i][0] && v[i][1] <= end ) // If start is same and ith end is still less than end, continue
                {
                    continue;
                }
                else if(start==v[i][0] && v[i][1] > end) // If start is same and end is higher than current end, update end.
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
