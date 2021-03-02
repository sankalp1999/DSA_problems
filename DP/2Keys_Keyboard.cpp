
// Prime factorization approach
class Solution {
public:
    int minSteps(int n) {
        int steps = 0;
        int i = 2;
        // We can observe that we can reach upto first divisor in 
        // in form of single pastes. To make a particular number,
        // you require operations == that number since 1A already there.
        // Copy and P-1 pastes.
        // N = g1 * g2 * g3 * g4 and so on(Prime factors)
        // Then one can keep pasting in terms of g2, g3, g4 and so on.
        // Since we are pasting g2 - 1 times (because one g2 already there) and 
        // copying once, operations = g2
        // So, the addition of the prime factors is our answer.
        while( i <= n)
        {
            while(n % i == 0)
            {
                n = n /i;
                steps += i;
            }
            i++;
        }
        return steps;
    }
};


class Solution {
public:
    set<pair<int,int>> s;
   int solve(int i, int j, int n)
   {
       int inf = 1<<30;
       if(i == n)
       {
           return 0;
       }
       else if(i > n)
       {
           return inf;
       }
       // Avoiding going to the same state again.
       if(s.find({i,j}) != s.end())
           return inf;
       else
           s.insert({i,j});
       int op1, op2;
       // COPY to clipboard
       op1 = 1 + solve(i, i, n);
       // Paste i + j chars and clipboard still has same j
       op2 = 1 + solve(i+j,j,n);
       return min(op1, op2);
   }

    int minSteps(int n) {
        int i = 1; 
        int j = 0;
        return solve(i,j,n);
    }
};