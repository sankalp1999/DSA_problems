/*
Since we want to make maximum profit, it is better to exploit every
peak and valley since we are allowed to buy and sell anytime provided we don't buy 
before selling

https://leetcode.com/media/original_images/122_maxprofit_1.PNG
For example, in the above case, if we skip peak_ipeak 
i
​	
  and valley_jvalley 
j
​	
  trying to obtain more profit by considering points with more difference in heights, the net profit 
  obtained will always be lesser than the one obtained by including them, since CC will always be lesser than A+B
*/

int Solution::maxProfit(const vector<int> &A) {
    
        if(A.empty())return 0;
        long long int curr = A[0];
        long long int max_profit = 0;
        for(int i = 1; i < A.size(); i++)
        {
            if(curr < A[i])
            {
                max_profit = max_profit +  (long long )A[i] - (long long)curr;
                if(i + 1 < A.size())
                curr = A[i];
            }
            else curr = A[i];
        }
    
        return max_profit;
    
    
}
