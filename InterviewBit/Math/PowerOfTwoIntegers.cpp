/*
This was an easy maths question.

Approach 1: Factor based sqrt(n) approach.
Approach 2: Log(n) approach

To find if A ^ P is possible,
we search all factors of A. All the factors of a number
can be found by iterating only till sqrt(A).

Now, the number of factors is going to be much less than A.
We can iterate over our factor list and if by dividing by that factor continously, 
if we are able to reach 1,
then we got our answer.

Time complexity:
O(sqrt(n)) to find factors.

log(n) required to calculate power. So, O(sqrt(n) * log(n))
*/

/*Approach 1*/

int Solution::isPower(int A) {
    
    int num = A;
    if(A == 1)return 1;
    set<int> factors;
    for(int i = 2; i <= sqrt(A); i++)
    {
        if(A%i==0)
        {
            factors.insert(i);
            factors.insert(A/i);
        }
    }
    vector<int> facts;
    for(auto it = factors.begin(); it != factors.end(); it++)
    {
        facts.push_back(*it);   
    }
    
    for(int i = 0; i < facts.size() ; i++)
    {
        int num = A;
        while(num%facts[i] == 0 && num != 1) // Check whether it can be raised to that power.
        {
            num = num/facts[i];
        }
        if(num == 1)return 1;
    }
    
    return 0;
}


/*Approach 2*/

/*
a = x ^ y
log a = y log x (by property of log)
log a / log x = y
So, if y is an integer, there exists such a combination where a = x ^ y
*/

bool isInt(float x)
{
    if(ceil(x) == floor(x))return true;
    else return false;
}

int Solution::isPower(int A) {
    
    int num = A;
    if(A == 1)return 1;
    for(int i = 2; i <= sqrt(A); i++)
    {
        if( isInt(log(A)/log(i)) )
        {
            return 1;
        }
    }
    return 0;
}




