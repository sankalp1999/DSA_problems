#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int v , n;
	    cin >> v >> n;
	    vector<int> coins(n,0);
	    for(int i = 0; i < n; i++)
	    {
	        cin >> coins[i];
	    }
	    int dp[n + 1][v + 1] ;
	    for(int i = 0; i <= n; i++)
	    {
	        for(int j = 0; j <= v ; j++)
	        {
	            dp[i][j] = INT_MAX - 1;
	        }
	    }
	    
	    for(int i = 0; i < n; i++)
	    {
	        dp[i][0] = 0; // For 0 amount, 0 coins are required.
	    }
	    
	    for(int i = 1; i <= coins.size(); i++)
	    {
	        for(int j = 1; j <= v; j++)
	        {
	            if(j - coins[i-1] >= 0)
	            {
	                //Case 1, don't include ith coin
	                // Case 2, include current coin and add one
	                dp[i][j] = min(dp[i-1][j], dp[i][j - coins[i-1]] + 1);
	            }
	            else dp[i][j] = dp[i-1][j];
	        }
	    }
	    if(dp[n][v] == INT_MAX - 1)cout << -1 << endl;
	    else
	    cout << dp[n][v] << endl;
	    
	}
	return 0;
}
