
/*Editorial solution */


int Solution::numDecodings(string A) {
    vector<int> dp(A.size()+1,0);
    dp[0]=1;
    if(A[0]=='0')
    dp[1]=0;
    else
    dp[1]=1;

    // It's much better in the sense not using any inbuilt functions
    for(int i=2;i<=A.size();i++)
    {
        if(A[i-1]>'0')
        dp[i]=dp[i-1];
        if((A[i-2]=='1') || (A[i-2]=='2' && A[i-1]<'7'))
        dp[i]=(dp[i-2]+dp[i])%1000000007;
    }
    return dp[A.size()];
}











/* My original solution */
#define mod 1000000007
int Solution::numDecodings(string A) {
    // Let dp[i] denote the ways till ith position
    // Note that '12', the number can be 1 or 12 while decoding
    // 12 is still starting from position i so it's result will be stored
    // position i
    
    int n = A.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    if(A[0] == '0')
    {
        dp[0] =0;
    }
    for(int i = 1; i <= n; i++)
    {
        if( (A[i - 1] - '0') >= 1 && (A[i - 1] -'0') <= 9)
        {
            dp[i] += dp[i - 1]%mod;
            dp[i] %= mod;
        }
        
        if(i - 2 >= 0 && stoi( A.substr(i-2,2)) >= 10 && stoi( A.substr(i-2,2)) <= 26)
        {
           
            dp[i] = dp[i] %mod + dp[i - 2]%mod;
            dp[i] %= mod;
        }
    }
    return dp[n];
}
