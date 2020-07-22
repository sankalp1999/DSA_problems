/*
If no duplicates, this style of code generates
[[1,2,3],[1,2],[1,3],[1],[2,3],[2],[3],[]]
If we have [1,2,2]
The 3 gets replaced by 2.
Hence we need to remove
[[1,2,3],[1,2],[1,3],[1],[2,3],[2],[3],[]]
                 |         |        |
So, in each step, we either choose or don't choose and go to next element.
If the next element is same, we skip it.

Also, there can be more than one duplicates. So, use a while loop.

*/
class Solution {
public:
    int flag  = 0;
    void dfs(vector<vector<int>>& subsets, vector<int>& nums, int i, vector<int>& p)
    {
        if( i == nums.size())
        {
            subsets.push_back(p);
            return;
        }
        p.push_back(nums[i]);
        dfs(subsets, nums, i + 1, p);
        p.pop_back(); // restore

    
        while(i + 1 < nums.size() && nums[i] == nums[i+1])i++;
        // [1,2,3] is now [1,2,2]. So,
        // not choosing or moving forward
        dfs(subsets, nums, i + 1 , p);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> p;
        sort(nums.begin(), nums.end());
        dfs(subsets, nums, 0, p);
        return subsets;
    }
};
