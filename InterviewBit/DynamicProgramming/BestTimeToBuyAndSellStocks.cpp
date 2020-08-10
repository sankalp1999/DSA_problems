int Solution::maxProfit(const vector<int> &A) {
    
    if(A.empty())return 0;
    int max_till = 0;
    int min_so_far = 1e8;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] - min_so_far > max_till )
        {
            max_till = A[i] - min_so_far;
        }
        min_so_far = min(A[i], min_so_far);
    }
    return max_till;
    
}
