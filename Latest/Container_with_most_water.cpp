class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftMax, rightMax;
        leftMax = rightMax = 0;
        leftMax = height.front();
        rightMax = height.back();
        int l = 0;
        int r = height.size() - 1;
        int cost = 0;
        int posl = 0;
        int posr = r;
        // At each stage, the width keeps decreasing
        // Also, we are bounded by the minimum of heights in both sides
        // We don't want to reduce maximum so we increment the 
        // min pointer in hope that we can get a new max length
        while(l < r)
        {   
            cost = max(cost, (r - l) * min(height[l], height[r]));
            if(height[l] < height[r])
            {
                l++;
            }
            else 
            {
                r--;
            }
        }
        
        return cost;
    }
};

