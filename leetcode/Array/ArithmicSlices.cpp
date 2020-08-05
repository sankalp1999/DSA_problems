class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int count = 0; // one repeat count happens
        int sequences = 0;
        if(nums.size() <= 2)return 0;
        
        
        int prev = nums[1] - nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] - nums[i-1] == prev)
            {
                count++;
            }
            else
            {
                if(count >= 2)
                {
                    count++; // Some adjustment since each difference reduces terms by 1
                    while(count >= 2) // Whole sequence using summation of l - r + 1. That is the no. of substrings embedded.
                    {
                        sequences += count - 2;
                        count--;
                    }
                }
                    count = 1;
            }
             prev = nums[i] - nums[i-1]; // To check for the next time.
        }
        
         if(count >= 2) // If we come out of loop without going through the else condition.
            {
            count++;
             while(count >= 2)
                {
                    sequences += count - 2;
                    count--;
                }
            }
        return sequences;
    }
};
