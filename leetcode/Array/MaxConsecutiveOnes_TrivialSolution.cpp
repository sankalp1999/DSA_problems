class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        
        /* Don't complicate easy stuff man */
        
        int curr_max = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                curr_max++;
                ans = max(ans, curr_max);
            }
            else
            {
                curr_max = 0;
            }
            
        }
        return ans;
    }
};
