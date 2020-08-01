/*
This question is similar to chain matrix multiplication.
We iterate over all the ranges.

main recurrence
solve(e - 1, k - 1) and solve(e, f - k)
If we dropped the egg from the kth floor and it broke, then we have e - 1 eggs left. Naturally, we will check downwards.

If we dropped the egg from kth floor and didn't break, we check from f - k (above, from there also, we will check below hence not k + 1)

This solution is O( e * f)
There is a better solution which does not give TLE on leetcode.
*/



#include <bits/stdc++.h>
using namespace std;

int dp[12][52];

int solve(int e, int f)
{
    if(f == 1 || f == 0)return f;
    if(e == 1)return f;
    if(dp[e][f] != -1)
        return dp[e][f];
    int mini = INT_MAX;
    for(int k = 1; k <= f; k++)
    {
        int temp = 1 + max(solve(e-1, k-1), solve(e,f-k )); // Worst case
        mini = min(mini, temp); // Minimum number of moves
    }
    return dp[e][f] = mini; 
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k; // k is no of floor
	    for(int i = 0; i <= n; i++)
	    {
	        for(int j = 0; j <= k; j++)
	        {
	            dp[i][j] = -1;
	        }
	    }
	    cout << solve(n, k) << endl;
	    
	}
	return 0;
}
