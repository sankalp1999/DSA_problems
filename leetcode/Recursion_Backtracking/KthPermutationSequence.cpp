class Solution {
public:
    string getPermutation(int n, int k) {
        
        string s = "";
        
        // This can be solved as a recursive problem.
        // k / fact( n - 1 ) gives the MSD position. We recursively 
        // solve for n - 1 and get the MSD's till n >= 1
        // Boundary check for k % fact(N - 1) == 0 required
        
        vector<long long int> fact;
        fact.push_back(1);
        fact.push_back(1);
        for(int i = 2; i <= n; i++)
        {
            if(fact[i-1] > k)
                fact.push_back(INT_MAX + 5LL); // After 12, the number exceeds long long. k < n!. So, if if fact[n-1] is above k, then in loop, we are going to get  zero
        // That is anyways going to happen for INT_MAX also. So, we don't compute and just add some INT_MAX + some number    
        
            else 
                fact.push_back(fact[i-1] * i);
        }
        
        vector<int> nums;
        for(int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        
        while(n >= 1)
        {
            int index = k / fact[n-1]; // MSD
            if(k % fact[n-1] == 0) // Boundary check. 
                index--;
            
            s += to_string(nums[index]);
            
            nums.erase(nums.begin() + index);
            
            k = k % fact[n-1] == 0 ? fact[n-1] : k % fact[n-1];
            
            n--; // Solve for next block of n
        }
        
        return s;
        
        
        
    }
};
