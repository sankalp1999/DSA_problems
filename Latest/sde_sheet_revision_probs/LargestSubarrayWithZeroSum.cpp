int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> m;
    m[0]=-1;
    long long int sum = 0;
    int min_id = INT_MAX;
    int max1 = 0;
    for(int i = 0; i < n; i++)
    {
        sum += A[i];
        if(m.find(sum) != m.end())
        {
            int idx = m[sum];// Some previous sum is also same
            max1 = max(max1, i - idx);
        }
        else m[sum] = i; // Important. Don't refresh the previous indices. That is why using else statement.
    }
    return max1;
}
