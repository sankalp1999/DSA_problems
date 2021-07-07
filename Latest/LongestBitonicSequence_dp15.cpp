// Easy problem if you know LIS
// Find the LIS. Then we want the LDS starting from ending at arr[i]. Accomplish that by reversing the array and then running LIS. Also reverse the dp array.
vector<int> LIS(vector<int>& nums)
	{
	    int n = nums.size();
	    vector<int> dp(n , 1);
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < i; j++)
	        {
	            if(nums[i] > nums[j])
	            {
	                // Then, we can add it to the subsequence
	                // or maybe not.
	                dp[i] = max(dp[i], dp[j] + 1);
	            }
	        }
	    }
	    return dp;
	}
	
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    vector<int> ltor = LIS(nums);
	    reverse(nums.begin(), nums.end());
	    vector<int> rtol = LIS(nums);
	    reverse(rtol.begin(), rtol.end());
	    int res = 0;
	    int n = nums.size();
	    for(int i = 0; i < n; i++)
	    {
	        
	        res = max(res, ltor[i] + rtol[i] - 1);
	    }
	    return res;
	}
