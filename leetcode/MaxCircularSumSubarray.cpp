
/*
https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
Prove of the second case
max(prefix+suffix)
= max(total sum - subarray)
= total sum + max(-subarray)
= total sum - min(subarray)

*/

int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }

class Solution {
public:
    typedef long long int lli;
    lli kadane(vector<int>& arr)
    {
        lli currSum = 0;
        lli currMax = INT_MIN;
        for(lli i : arr)
        {
            currSum += i;
          
            if(currSum < 0)
            {
                currSum = 0;
            }
             currMax = max(currMax, currSum);
            
        }
        return currMax;
    }
    
    
    int maxSubarraySumCircular(vector<int>& A) {
        lli non_wrap = kadane(A);
        lli total_sum = 0;
        int n = A.size();
        int _max = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            total_sum += A[i];
            _max = max(A[i],_max);
            A[i] = -1 * A[i];
        }
        lli wrap = total_sum + kadane(A);
        
        if( max(wrap,non_wrap) == 0)
        {
            return _max;
        }
        
        return max(wrap, non_wrap);
    }
};





