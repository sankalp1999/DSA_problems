   int countFriendsPairings(int n) 
    { 
        // code here
        int mod = 1e9 + 7;
        vector<long long int> dp(n + 1, 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        // f(n) = f(n - 1) + (n - 1) * f(n - 2);
        // Either you go solo. Then subproblem reduces to 
        // to f(n - 1) ordered way
        // or you pair up.
        // (n - 1) * f(n - 2) since you have n - 1 cohies to pair up 
        // and you evaule for (n - 1) f(n - 2) subproblems.
        // f(n) = f(n - 1) + 1 * f(n - 2) + f(n - 2) ... n - 1 times
        
        for(int i = 3; i <= n; i++)
        {
            dp[i] = 1 * dp[i-1] % mod + ((i-1) * dp[i - 2])%mod;
            dp[i] = dp[i]%mod;
        }
        return dp[n];
    }
