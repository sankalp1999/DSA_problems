/*
It is very disappointing that I got TLE in this question.
This is very similar to what I have done earlier.

In the TLE attempt, I was using two pointers approach. I should have used set approach of the 2 sum problem.

In this code, if i is prime, just check if A - i is prime.
If both are prime, then return.

Time complexity: O( n * sqrt(n))

Learning: Think a bit more. I think i was fatigued while solving this problem.
*/


bool isPrime(int n)
{
       for(long long int j = 2; j <= sqrt(n); j++)
        {
            if(n % j == 0)
            {
                return false;                
            }
        }
        return true;
}
vector<int> Solution::primesum(int A) {
    
    // Generate all prime numbers before A.
    int flag = 0;
    unordered_set<int> s;
    vector<int> p;
    for(long long int i = 2; i <= A; i++)
    {
        if(isPrime(i) && isPrime(A-i)) // When you see i, check for A - i also.
        {
            p.push_back(i);
            p.push_back(A - i);
            break;
        }
    }

    return p;    
}
