#define lli long long int
#define mod 1000000007

lli cache[1000][1000];
lli dp(lli n, lli s, lli sum, lli size)
{
    if(sum > s)
    {
        return 0;
    }
    if(size == n)
    {
        if(sum == s)return 1;
        else return 0;
    }
    if(cache[sum][size] != -1)
    {
        return cache[sum][size];
    }
    lli ans = 0;
    for(int i = 0; i <= 9; i++)
    {
        if(size == 0 && i == 0) continue;
        ans = (ans%mod + dp(n, s, sum + i, size + 1 )%mod)%mod;
    }
    return (cache[sum][size] = ans);
}



int Solution::solve(int A, int B) {
    
    lli n = A*1LL;
    lli s = B*1LL;
    lli sum = 0;
    lli size = 0 ;
    memset(cache, -1, sizeof cache);
    return dp(n, s, sum, size);
    
    
}
// 478432066
