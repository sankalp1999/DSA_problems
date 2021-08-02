int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       // dp[i][j] defines the max value which we can obtain 
       // with the first i items if weight <= j
       int dp[n+1][W+1];
       memset(dp,0,sizeof dp);
       // Base case?
       // For w = 0
       // For i = 0?
       for(int i = 1; i <= n; i++)
       {
           for(int j = 1; j <= W; j++)
           {
               int weight = wt[i-1];
               if(j - weight >= 0)
               {    
                   // Take or do not take
                   dp[i][j] =  max(dp[i-1][j],dp[i-1][j - weight] + val[i-1]);
               }
               else
               dp[i][j] = max(dp[i][j],dp[i-1][j]); // we can't take current item
           }
       }
       return dp[n][W];
    }
