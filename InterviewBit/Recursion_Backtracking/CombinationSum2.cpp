
void helper(vector<int>& A, int B, int sum, vector<vector<int>>& res, vector<int>& temp, int begin)
{
    
    if(sum == B)
    {
        res.push_back(temp);
        return;
    }
    
    if(sum > B || begin >= A.size())
        return;
  
    // Suffix based recursion
    for(int i = begin ; i <  A.size(); i++)
    {
        if(i > begin && A[i] == A[i-1])continue; 
        // We will eventually get that element in the next call.
        // If we call from both the A[i] in this call, then we will have duplicates
        
        temp.push_back(A[i]);
        helper(A,B,sum + A[i], res, temp, i + 1 );
        temp.pop_back(); // We can take unlimited times
    }
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    vector<vector<int>> res;
    vector<int> temp;
    int sum = 0;
    int begin = 0;
    
    sort(A.begin(), A.end());
    
    helper(A, B, sum,res, temp, begin );
    return res;
}
