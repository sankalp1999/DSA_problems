class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size() ;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n - 3; i++)
        {
            for(int j = i+1; j < n - 2; j++)
            {
                
                int t = target - nums[i] - nums[j];
                int left = j+1;
                int right = n - 1;
                while(left < right)
                {
                    int sum = nums[left] + nums[right];
                    if(sum == t)
                    {   
                        // cout << "YES" << endl;
                        vector<int> temp = {nums[i],nums[j],nums[left],nums[right]};
                        res.push_back(temp);
                        while(left+1<right and nums[left] == nums[left+1])left++;
                    
                        while(right-1>left and nums[right] == nums[right-1])right--;
                            left++;
                        right--;
                    }
                    else if(sum < t)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
                // For loop will automatically go to next number
                while(j+1< n-2 and nums[j] == nums[j+1])j++;
            }
            // For loop will automatically go to next number
            while(i + 1< n- 3 and nums[i] == nums[i+1])i++;
        }
        return res;
    }
};
// [2,2,2,2,2]
// -2 -1 0 0 1 2
