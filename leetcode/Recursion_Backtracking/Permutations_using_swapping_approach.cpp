/*
1 2 3
main -> permuteHelper(res,nums,0)
Call 0  skip base case. Go to loop.
begin = 0 and i = 0. swap(nums[0],nums[0]) no effect. permuteHelper(res, nums, 1) 
Call 1 --> i = 0 begin = 1
skip base case. swap(nums[0], nums[1]) --> 2 1 3. permuteHelper(res, nums, 2)

Call 2 --> i = 0 and begin = 2 skip base case. swap(2,0) -> 3 1 2 permuteHelper(res, nums, 3)

Call 3 -->  base case hit since begin = 3. res.push_back([3,1,2]) --> return back to loop. We skip the loop . Call 3 is done.

Call 2 resumes inside the loop. swap(2,0) --> 2 1 3. i = 1. Swap(1,2)--> 2 3 1 permuteHelper(res, nums, 3) 

Call 4 Hit the base case. Print( 2 3 1)

so on.........

Time complexity : O(n!)

*/

class Solution {
public:
    void permuteHelper(vector<vector<int>>& res, vector<int>& nums, int begin)
    {
        if(begin >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++)
        {
            swap(nums[i], nums[begin]);
            permuteHelper(res,nums,begin+1);
            swap(nums[i],nums[begin]); // reset to return to previous state. We are passing by reference. So, vector is being restored to 
                                       // to its previous state.
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        int begin = 0;
        permuteHelper(res, nums, begin);
        return res;
    }
};

