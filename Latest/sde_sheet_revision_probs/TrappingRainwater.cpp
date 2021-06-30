class Solution {
public:
  // O(n) time, O(1) space
    int trap(vector<int>& height)
    {
        if(height.empty())
            return 0;
        int leftMax, rightMax;
        int n = height.size() ;
        leftMax = height[0];
        rightMax = height[n - 1];
        int l = 0;
        int r = n - 1;
        int res = 0;
        while(l < r)
        {   
            // We know that the bottleneck is the minimum one
            // So we move whichever pointer is minimum
            if(leftMax < rightMax)
            {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            }
            else
            {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
    
    // O(n) space, O(n) time
    int trap(vector<int>& height) {
        if(height.empty())return 0;
        const int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0]=height[0];
        for(int i = 1; i < n; i++)
        {
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1]=height[n-1];
        for(int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i+1], height[i]);
        }
        int cost = 0;                                       
        for(int i = 0; i < n;i++)
        {  
            int diff = min(i-1>=0?left[i-1]:0, i+1<n?right[i+1]:0);
            // cout << left[i-1] << " " << right[i+1] << " "<< diff - height[i] << endl;
            cost += max(0, diff - height[i]);
        }
        return cost;
    }
};
