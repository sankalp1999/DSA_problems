//A proof sketch:
        // Suppose sum_i represents the running sum starting from index 0 and ending at i
        // once we find a mod that has been seen, say modk, we have:
        
        // current one: sum_i = m*k + modk
        // previous one: sum_j = n*k + modk
        // Thus,
        // sum_i - sum_j = (m - n) *k
        
        //so if two runningSum mod k have the same values, then when they are subtracted, they are bound to be multiples of k

        //base checking - first check if the size of the array is less than 2


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,vector<int>> m;
        // Store indices as well.
        int n = nums.size();
        int sum = 0;
        m[0].push_back(-1);
        for(int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % k;
          
            if(m.find(sum) != m.end())
            {
                vector<int> temp = m[sum];
                
                for(int j : temp)
                {
                    // cout << sum << endl;
                    if(i - j > 1 ) // Since F[i] - F[j] (sum 0..i - sum 0.. j)
                        return true;
                }
            }
            m[sum].push_back(i);
        }
        return false;
    }
};

// The sum i am storing is 0 to i
// j is 0 to j 
// j - i

//
