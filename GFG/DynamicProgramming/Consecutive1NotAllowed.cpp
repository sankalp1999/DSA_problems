	const int mod = 1e9 + 7;
	int dp[100001][2];
	ll solve(int n, int prev, int idx)
	{
	    if(idx == n)
	    return 1;
	    if(dp[idx][prev] != -1)return dp[idx][prev];
	    ll res = 0;
	    if(prev != 1)
	    {
	        res = res % mod + solve(n, 1, idx + 1 )% mod;
	        res = res % mod;
	        res = res % mod + solve(n , 0 , idx + 1) % mod;
	        res = res % mod;
	    }
	    else if(prev == 1)
	    {
	        res = res % mod + solve(n, 0, idx + 1) % mod;
	        res = res % mod;
	    }
	    return dp[idx][prev] = res;
	}
	
	ll countStrings(int n) {
	    // code here
	    int idx = 0;
	    memset(dp,-1,sizeof(dp));
	    return solve(n, 0, idx);
	}
