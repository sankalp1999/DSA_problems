int Solution::lis(const vector<int> &A) {
    
    
    vector<int> dp(A.size() + 1, 1); // ALl will have a length of 1 by default
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < i; j++) // Check if we can add a particular element to an existing smaller LIS
        {
            if(A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
    
    
}
