// Time complexity : O(n * log ( n )) Sorting 
// Possible to do in O(n) by finding the median using partitioning.
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int choose = nums[n/2]; // Choose the median and you are sorted in life.
        int count = 0;
        for(int i : nums)
        {
            count += abs(i - choose);
        }
        return count;
    }
};
