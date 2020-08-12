/*
First, we check whether the last index is reachable or not.
We do this by checking from the lastposition whether that position is reachable by the current position.
If LastGoodIndex is greater than 0, then we can't reach the end. Return -1.
Otherwise, we implement the greedy solution in which we travel over the steps which 
can be reached by jumping from the current position. In our journey, we store the max jump that 
can be done between [currBegin, currEnd]. So, when we reach the currEnd, we perform this maxjump.


int Solution::jump(vector<int> &A) {
    
    
    vector<int> visited(A.size() + 1, 0);
    vector<int> dp(A.size() + 1, 1e7);
    int LastGoodIndex = A.size() - 1;
    // First check if we can reach i == 0
    int i;
    for(i = A.size() - 2; i >= 0; i--)
    {
        if(i + A[i] >= LastGoodIndex)
        {
            LastGoodIndex = i;
        }
    }
    if(LastGoodIndex > 0)
        return -1;
        
    int jump = 0;
    // we can reach the end
    
    int pos = 0;
    int dest = 0;
        
    for(int i = 0; i < A.size() - 1; i++)
    {
        dest = max(dest, i + A[i]); // Keep track
        
        if(pos == i) // Trigger jump --> that is the maxjump
        {
            pos = dest; // We will jump 
            jump++;
        }
    }

    return jump;
        
    
    
    
}
