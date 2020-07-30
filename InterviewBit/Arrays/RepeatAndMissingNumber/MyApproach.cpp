/*
This was more of a mathematics question. We form two equations and solve using that.
Be sure to handle int overflows. Linear time and space solution.
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    long long int K, C;
    K = 0;
    C = 0;
    for(long long int i = 1; i <= A.size(); i++)
    {
        K = K + ( (i) - (long long)A[i-1] );
        C = C + (  (i) * (i) -  (long long)A[i-1] * (long long)A[i-1] );
    }

    vector<int> res;
    long long int B = (long long)(C - K * K)/(2 * K);
    long long int a = K + B;
    
    int flag  =0;
    int flag2 = 0;    
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == a)flag++;
        if(A[i]== B)flag2++;
    }
    if(flag==2)
    {
        res.push_back(a);
        res.push_back(B);
    }
    else
    {
        res.push_back(B);
        res.push_back(a);
    }
    return res;
    
}
