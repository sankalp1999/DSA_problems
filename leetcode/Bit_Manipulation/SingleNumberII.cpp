














/* More general solution which is also more intuitive */
// Here, I just count the bits. For the numbers which appear,
// thrice, they will have that particular bit set 3 times.
// The number which appears only once, that particular
// bit will be set only 3n + 1 time.

 int res = 0;
        for(int i = 0; i < 32; i++)
        {
            int countBits = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                if((1 << i) & nums[j])
                {
                    countBits++;    
                }
            }
            if(countBits % 3 != 0)
            {
                res = res | (1 << i);
            }
        }
        return res;

/* Non-intuitive solution */
/*
In this solution, ones ^ nums[i] is equivalent to 
checking that the nums[i] is already there in the ones
set or not. If it is, then those bits get unset.
If it is not, then those bits get set.

If those bits get set and "twos" set is also not having them,
then since we are complementing "twos", those bits get 
set in two and "Bitwise AND" causes to insert the number
inside ones.

We do a similar thing for "twos" set which stores
only the numbers which have come twice since I think the
number which are removed from "ones" get inside two.

If a number comes thrice, it gets removed from both.
*/



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ones, twos;
        ones = twos = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }
        return ones;
       
    }
};
