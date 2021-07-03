// Just try to think. Think a little out of box.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> v;
        int start, end;
        sort(intervals.begin(), intervals.end());
        start = INT_MAX;
        end = -1;
        v.push_back(intervals[0]);
        // This solves two problems. 1. I can easily change end time if i find overlapping intervals.. 2. I can iterate till last.
         for(int i = 1; i < intervals.size(); i++)
        {
            if(v.back()[1] >= intervals[i][0] )
            {
                v.back()[1] = max(v.back()[1],intervals[i][1]);
            }
            else
            {
                v.push_back(intervals[i]);
            }
        }
            return v;
        }
    
};
