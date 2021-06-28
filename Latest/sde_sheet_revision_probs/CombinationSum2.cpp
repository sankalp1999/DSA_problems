class Solution {
public:

// If you do the non-for loop version then
// check i + 1 < size and nums[i] == nums[i + 1] coz in this, we are the first occurence again after considering it once.


    
    void solve(vector<int>& candidates, int target, vector<vector<int>>& v, vector<int>& temp, int sum, int idx)
    {
        if(sum > target)return;
        if(sum == target)
        v.push_back(temp);
        for(int i = idx; i < candidates.size(); i++ )
        {   
            if(i!=idx and candidates[i] == candidates[i-1])continue;
            // We don't choose same element again at same level of recursion.
            // When we return back, we are at the same level and check whether 
            // we are gonna call 
            // via a duplicate.
            temp.push_back(candidates[i]);
            solve(candidates,target,v,temp,sum+candidates[i], i+1);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        int idx = 0;
        solve(candidates, target, v, temp, sum, idx);
        return v;
    }
};
