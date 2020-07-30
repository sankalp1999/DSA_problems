/*
In this solution, i try to determine the correct position for the starting as I was initially
thinking in terms of using only one variable. But that approach gave TLE.
Also, counting I and D in advance helps in deciding the position but it is not required.

To tackle the TLE, I thought of using two pointers after seeing hint. Bascially, 
maintain left and right pointer. If I encounter I, then i increase right pointer and add it to result
If I encounter D, then i decrement left and add it to result

Only maintaining two pointers is sufficient as the problem want "any" permutation.
*/



vector<int> Solution::findPerm(const string A, int B) {
    
    vector<int> visited(B + 1, 0);
     
    // Counting 
    int countD, countI;
    countD = 0;
    countI = 0;
    for(char c : A)
    {
        if(c == 'I')
        {
            countI++;
        }
        else if(c == 'D')
        {
            countD++;
        }
    }
    
    int start = 0;
    // Deciding from where to start, again one of the ifs can be omitted 
    if(countD > countI)
    {
        start = countD + 1;
    }
    else if(countI >= countD)
    {
        start = B - countI;
    }
   
    vector<int> res;
    
    int left, right;
    left = start;
    right = start;
    res.push_back(start);
    
    visited[start] = 1;
    for(char c : A)
    {
        if(c == 'I')
        {
            right++;
            res.push_back(right);
        }
        else if(c == 'D')
        {
            left--;
            res.push_back(left);
        }
    }
    
    return res;
}
