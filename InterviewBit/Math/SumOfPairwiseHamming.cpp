/*
This is the optimal solution to this question.

The number of 1's when we do A xor B is the hamming distance. In other words, it's the number
of positions where the bits in the numbers are different.

We count all the 1's and 0' since XOR of different parity digits is 1 which is the hamming distance.

Total number of ones will be Number of 1's multipled by Number of 0's.
Since, we are consider pairwise elements without order, we multiply by 2.

*/

int Solution::hammingDistance(const vector<int> &A) {
        
    long long int sum = 0;
    int count = 0;
    int mod = 1e9 + 7;
    for(int i = 0;i < 32; i++) // Iterate through the bits. There are more bit-manipulation ways to do this also.
    {
        count = 0;
        for(int j = 0; j < A.size(); j++)
        {
            if( (A[j]) & ( 1 << i) ) // Get the ith bit in A[j]
            {
                count++;
            }
        }
        sum = ((sum%mod) +  (2 * count * (A.size() - count)%mod))%mod;
    }
    return sum % mod;
}
