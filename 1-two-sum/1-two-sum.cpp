class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        unordered_map<int,int> mapper;
        for(int i = 0; i < nums.size(); i++)
        {
            mapper[nums[i]] = i;
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mapper.find(target - nums[i]) != mapper.end() )
            {
                int ind = mapper[target-nums[i]];
                if(ind != i){
                res  = {mapper[target-nums[i]], i};
                return res;
                    
                }
            }
        }
        return res;
    }
};