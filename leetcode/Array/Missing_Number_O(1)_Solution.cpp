class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int sum = 0;
        for(int i : nums)
        {
            sum += i;
        }
        int n = (int)nums.size();
        
        long long int shouldbe = n * (n + 1);
        shouldbe = shouldbe/2;
        return shouldbe - sum;
    }
};
