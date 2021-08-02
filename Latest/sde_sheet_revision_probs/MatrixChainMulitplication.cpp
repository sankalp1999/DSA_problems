 int solve(int left, int right, int arr[],vector<vector<int>>& dp)
    {
        if(left + 1 >= right )
        {
            return 0;
        }
        if(dp[left][right] != -1)
        return dp[left][right];
    //   k = 1 k < 3
    //   k will run till k = 1, k = 2
    //   0 * 1 * 3
    //   0 * 2 * 3
    //   left = 0; right = 2;
    //   k = 1
    //   left * k * right
    //   (left, 1) + (1, 2)
       
        int res = INT_MAX;
        for(int k = left + 1; k < right; k++)
        {   
            res = min(res, solve(left,k,arr,dp) + solve(k,right,arr,dp) + arr[left] * arr[k] * arr[right]);
        }
        return dp[left][right] = res;

       
    }


    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int left = 0;
        int high = N-1;
        vector<vector<int>> dp(N+1,vector<int>(N+1, -1));
        return solve(left,high,arr,dp);
    }
