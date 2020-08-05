

void helper(vector<int>& A, int B, int sum, vector<vector<int>>& res, vector<int>& temp, int begin)
{
    
    if(sum > B || begin >= A.size())
        return;
    if(sum == B)
    {
        res.push_back(temp);
        return;
    }
    
    // Suffix based recursion
    for(int i = begin ; i <  A.size(); i++)
    {
        
        temp.push_back(A[i]);
        
        helper(A,B,sum + A[i], res, temp, i ); // First call without moving index to repeat values
                                               // When sum exceeds the target, it will backtack automatically and go to next number.
        temp.pop_back(); // We can take unlimited times
        
    }
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    vector<vector<int>> res;
    vector<int> temp;
    int sum = 0;
    int begin = 0;
    vector<int> send;
    set<int> s;
    for(int i = 0; i < A.size(); i++)
    {
        s.insert(A[i]); // To sort and get unique numbers.
    }
    
    for(auto it = s.begin(); it != s.end(); it++)
    {
        send.push_back(*it);
    }
    helper(send, B, sum,res, temp, begin );
    return res;
}
