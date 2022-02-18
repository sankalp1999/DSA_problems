// Updated 2022

int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> mapper;
        int sum = 0;
        int max_len = 0;
        for(int i = 0; i < n; i++)
        {
            sum += A[i];
            
            if(sum == 0)
            {
                max_len = max(max_len, i + 1);
                // Should have thought of i + 1 man
            }
            
            if(mapper.find(sum) != mapper.end())
            {
                max_len = max(max_len, i - mapper[sum]);
            }
            else
            mapper[sum] = i; // only first occurence of that sum
            // to optimize the largest subarray
        }
        return max_len;
}


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
