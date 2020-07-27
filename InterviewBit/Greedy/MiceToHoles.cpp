/*
Main Idea
- The minimum time for each mouse is achieved by getting to the closest hole. So, we allot the closest holes to the mice.
- Consequently, the maximum minimum difference is our answer.

Safe Move : Allot mice to their nearest holes.
This way, it will take minimum time for each of the mice to reach to their hole.

*/


int Solution::mice(vector<int> &A, vector<int> &B) {
    
    sort(A.begin(), A.end()); // Sort both the vectors
    sort(B.begin(), B.end()); 
    
    int diff = 0;
    for(int i = 0; i < A.size(); i++)
    {
        diff = max(diff, abs(A[i] - B[i])); // Allot each mice to nearest hole.
    }

    return diff;
    
}
