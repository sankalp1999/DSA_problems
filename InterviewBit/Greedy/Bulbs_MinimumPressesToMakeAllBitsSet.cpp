int Solution::bulbs(vector<int> &A) {

    int x = 0;
    int count = 0;
    
    // Go from left to right since only the right part of the array gets affected.
    // Left part of the array does not get affected.
    for(int i = 0 ;i < A.size(); i++)
    {
        if(x ^ A[i] == 0)
        {
             x ^= 1;
             count++;
        }
    }
    return count;
}
