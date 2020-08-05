/*
We use prefix and suffix products. Till i-1th position and i+1th position and calculate product using that.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();       
        
        vector<int> prefix;
        
        vector<int> suffix(n + 1);
        
        suffix[n] = 1;
        
        prefix.push_back(nums[0]); // Stick to a method of making prefix and suffix arrays.
        
        for(int i = 1; i < nums.size(); i++)
        {
            prefix.push_back(prefix.back() * nums[i]); // 1.2.i-1 * i+1,i+2..n
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            suffix[i] = (suffix[i+1] * nums[i]);
        }
        
        vector<int> output;
        output.push_back(suffix[1]);
        
        for(int i = 1; i < nums.size(); i++)
        {
            output.push_back(suffix[i + 1] * prefix[i-1]);
        }

        return output;
    }
};
