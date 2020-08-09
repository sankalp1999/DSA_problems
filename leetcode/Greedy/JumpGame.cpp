class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int LastIndex = nums.size() - 1;
        // DP approach or rather brute force is O(n^2) and gives TLE
        // Instead, there is a linear time approach where we check from the last index whether we can reach the next few positions. If we are able to reach the 
        // start index,  then we can reach the end index!
        for(int i = nums.size() - 2; i>=0; i--)
        {
            if(i + nums[i] >= LastIndex) // Check whether if there is some position from where we can reach current position. Update that position to this position.
            {
                LastIndex = i;
            }
        }
        if(LastIndex == 0)return true;
        else return false;
        
    }
};
