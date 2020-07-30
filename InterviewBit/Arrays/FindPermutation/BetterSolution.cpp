/* 
Any permutation is valid.
So, just use two pointers and in the end, append the right pointer.

When we encounter I, we should spit out the smallest number available. This way, we will have more numbers available for the future.
Same goes for encountering D.

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
