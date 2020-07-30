/* 
Any permutation is valid.
So, just use two pointers and in the end, append the right pointer.
*/

vector<int> Solution::findPerm(const string A, int B) {
    
    vector<int> visited(B + 1, 0);
   
    vector<int> res;
    
    int left, right;
    left = B;
    right = 1 ;
    
    for(char c : A)
    {
        if(c == 'I')
        {
            res.push_back(right);
            right++;
        }
        else if(c == 'D')
        {
            res.push_back(left);
            left--;
        }
    }
    
    res.push_back(right);
    
    return res;
    
    
    
}
