class Solution {
public:
    double myPow(double x, int n) {
        
        bool flag = 0;
        long long int b = n;
        if(n < 0) // Also, can raise 1/x to n alternatively
        {
            flag = 1;
            b = b * -1;
        }
        double res = 1;
        while(b>0)
        {
            if(b%2==1)res = res * x;
            x = x * x;
            b = b / 2; 
        }
        
        if(flag == 1)
        {
            res = 1/res;
        }
        return res;
        
    }
};

/* Recursive implementation */
class Solution {
public:
    
    double power(double a, long long int b, double res)
    {

        if(b == 0)
            return 1;
        double temp = power(a,b/2, res);
        res = temp * temp;
        if(b%2==1)
            res = res * a;
        return res;
    }
    
    double myPow(double x, int n) {
        
        long long int b;
        if(n < 0)
            b = (long long )n * -1;
        else 
            b = n;
        double res = 1;
        res = power(x, b, res);
        if(n < 0)
        {
            res = 1/res;
        }
        return res;
        
    }
};
