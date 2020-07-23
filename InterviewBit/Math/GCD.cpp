/*
Lets say g is gcd(m, n) and m > n.

m = g * m1
n = g * m2

m - n = g * (m1 - m2)

gcd (m, n) = gcd(m-n, n)

This implies the fact if we have two numbers x and y where y > x
gcd(x,y) = gcd(x, y-x) 
Extending this, gcd(x,y) = gcd(x, y -x -x -x -x till it becomes lesser than x)

gcd(x,y) = gcd(x,y%x)

*/

int helper(int a, int b)
{
    if(b == 0)return a;
    return helper(b , a % b );
}

int Solution::gcd(int A, int B) {
    return helper(A, B);
}
