/*
Lets say we are at index start then we can swap element at this index with any index>start 
and permute the elements starting from start+1 using recursion. You can swap back the elements at start and 
index in order to maintain the order for next recursive call.
*/


void permuter(vector<vector<int>>& res, vector<int>& A, int begin)
{
    if(begin >= A.size())
    {
        res.push_back(A);
        return;
    }
    
    for(int i = begin; i < A.size(); i++)
    {
        swap(A[i], A[begin]); Recursively, permute remaining A - 1, A- 2 etc....
        permuter(res, A, begin + 1); 
        swap(A[i], A[begin]); // Reset for next permutation call
    }
}


vector<vector<int> > Solution::permute(vector<int> &A) {
    
    vector<vector<int>> res;
    permuter(res, A, 0);
    return res;
}
