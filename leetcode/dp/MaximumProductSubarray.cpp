class Solution {
public:
    
    /*
Extension of kadane algorithm. In this question,
we have three choices at each point,
1. If the current element is positive, we will multiply it with curr_max_prod
2. IF the current element is negative, it will make our curr_max_prod negative if curr_max prod is positive and negative number can act as curr_min, so we maintain another variable that is the curr_min product. Now, if we multiply negative element with curr_min_prod, it can give a larger number
3. We want to start a new subarray
*/
    
    
    /*
    -1, 6, 2 , -2
           ^ At 2, we have running product as -12. But if we multiply with -2,
           we get our max prod. I should have thought about the negative case 
           separately. This question was doable.
           so, we keep another variable curr_min_prod and prev_min_prod
    */
    
    
    
    int maxProduct(vector<int>& nums) {
        int curr_max_prod, curr_min_prod;
        int prev_max_prod = nums[0];
        int prev_min_prod = nums[0];
        
        int res = nums[0]; // To handle edge case of one element
        for(int i = 1; i < nums.size(); i++)
        {
            curr_max_prod = max({prev_max_prod * nums[i], prev_min_prod * nums[i], nums[i] });
            curr_min_prod = min({prev_max_prod * nums[i], prev_min_prod * nums[i], nums[i]});
            res = max({curr_max_prod, res, curr_min_prod});
            prev_max_prod = curr_max_prod;
            prev_min_prod = curr_min_prod;
        
        }
        return res;
    }
};
