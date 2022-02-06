class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        unordered_map<int,int> mapper;
        
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mapper.find(target - nums[i]) != mapper.end() )
            {
                res  = {mapper[target-nums[i]], i};
                return res;
                    
            }
            mapper[nums[i]] = i;
        }
        
        return res;
    }
};