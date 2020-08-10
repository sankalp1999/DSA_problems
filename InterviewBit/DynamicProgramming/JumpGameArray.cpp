/*
Greedy solution
Check if the lastGoodIndex is reachable from an index
*/

int Solution::canJump(vector<int> &A) {
    
    int LastIndex = A.size() - 1;
    for(int i = A.size() - 2; i >= 0; i--)
    {
        if( i + A[i] >= LastIndex)
        {
            LastIndex = i;
        }
    }
    return LastIndex == 0;
    
}
