int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    long long int sum = 0;
	    for(int i = 0; i < n; i++)
	    {
	        sum += static_cast<long long int>(arr[i]);
	    }
	    vector<int> dp(sum + 1, 0);
	    dp[0] = 1;
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = sum; j >= 0; j--)
	        {
	            dp[j] = dp[j] | dp[j];
	            if(j - arr[i] >= 0)
	            {
	                dp[j] |= dp[j - arr[i]];
	            }
	        }
	    }
	    
	    int min_diff = sum;
	    for(int i = 0; i <= sum; i++)
	    {
	        if(dp[i])
	        {
	            int s1 = i;
	            int s2 = sum - i;
	            min_diff = min(min_diff, abs(s1 - s2) );
	        }
	    }
	    return min_diff;
	} 
