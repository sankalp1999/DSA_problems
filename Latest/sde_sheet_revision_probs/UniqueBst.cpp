// Good job. Was able to solve on own completely.

// Fix the head node.
// Now, following bst invariant, only x nodes can go on left if they are 
// smaller than the root.  n - x - 1 will go to right. Now, left * right ways should give 
// the total answer.



class Solution
{
    public:
    const int mod = 1e9 + 7;
    //Function to return the total number of possible unique BST. 
    long long int dp[1001];
    long long int solve(int n)
    {
        if(n  == 0 )
        {
            return 1;
        }
        if(n <= 2 )return n;
        if(dp[n]!=-1)return dp[n];
        long long int res = 0;
        for(int i = 0; i < n; i++)
        {
            res = (res%mod + (solve(n - i - 1) * solve( i ) ) % mod) % mod; 
        }
        return dp[n] = res;
    }
    
    
    
    
    int numTrees(int N) 
    {
        memset(dp, -1, sizeof dp);
        return solve(N);
    }
