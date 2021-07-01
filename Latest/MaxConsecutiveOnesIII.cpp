class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int maxi = 0;
        int n = nums.size();
        // [1,1,1,0,0,0,1,1,1,1,0]
        while(right < n)
        {   
          
            if(nums[right] == 0 and k > 0)
            {
                right++;
             
                k--;
            }
            else if(nums[right] == 1)right++;
            else
            {
                if(nums[left] == 0)
                {
                    left++;
                    k++;
                }
                else left++;
            }
             maxi = max(maxi, right - left);
        }
        return maxi;
    }
};
