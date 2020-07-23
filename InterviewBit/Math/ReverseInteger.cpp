/*
Notable feature
Use long long int to be on the safe side. 
Keep checking for overflow since on reversing, the least significant digit becomes most significant.
So, theres chance to overflow if it becomes greater > 2^31 i.e MSD is > 2.
*/
int Solution::reverse(int A) {
    
    bool minus = false;
    if(A < 0)
    {
       minus = true;
       A = A * -1;
    }
    long long int sum = 0;
    while(A)
    {
        if(sum <= INT_MIN || sum >= INT_MAX)
            return 0;
        sum = sum*10 + A%10;
      
        A = A/10;
    }

    if(sum < INT_MIN || sum > INT_MAX)return 0;
    if(minus)sum = sum * -1;
    return sum;
    
}
