https://www.interviewbit.com/problems/majority-element/
/*
This version uses Moore's voting algorithm. For more details, check editorial solution on Leetcode.
https://leetcode.com/articles/majority-element/
*/
int Solution::majorityElement(const vector<int> &A) {
    
    int count = 0;
    int candidate = 0; // We choose a candidate
    for(int i = 0; i < A.size(); i++)
    {
        if(count == 0) // Choose a new candidate
        {
            candidate = A[i];
        }
        count += (A[i] == candidate ? 1 : -1); // We vote for that candidate if the array element 
    }
    return candidate;
}
