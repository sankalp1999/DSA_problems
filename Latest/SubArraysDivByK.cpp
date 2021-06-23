

// Fj - Fi == N * K
// Fj % k  == Fi  % k since (n * k) % k == 0 
// Make sure to bring the remainder in the positive field since we 
// want positive remainder. Negative remainder might 
// match with some other sum.


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        int n = nums.size();
        long long int sum = 0;
        int count = 0;
        m[0]=1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i])%k ;
            if(sum < 0)sum += k;
            if(m.find(sum % k) != m.end())
            {
                count += m[sum % k];
            }
            
            m[sum%k]++;
        }
        return count;
    }
};
