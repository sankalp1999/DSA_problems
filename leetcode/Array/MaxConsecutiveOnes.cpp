class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pt = 0;
        int occ = 0;
        int i;
        for(i = 1 ; i < nums.size(); i++)
        {
            if(nums[i] != nums[pt])
            {   
                if(nums[pt] == 1)
                occ = max(occ, i - pt);
                pt = i;
            }
        }
        if(nums[pt] == 1)
        occ = max(occ, i - pt);
        return occ;
    }
};
