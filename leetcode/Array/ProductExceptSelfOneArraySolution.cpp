class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // O(n) space solution with only one array
        vector<int> output;
        // Use this as a prefix array
        const int n = nums.size();
        int suffix = 1; // Calculate this while iterating from left
        
        output.push_back(1);
        for(int i = 1; i < n; i++)
        {
            output.push_back(output.back() * nums[i-1]);
        }
        
        for(int i = n-1 ; i >= 0; i--)
        {
            output[i] = output[i] * suffix;
            suffix = suffix * nums[i];
        }
        return output;
    }
};
