class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> s;
        int n = heights.size();
        int width = 0;
        long long int area = 0;
        for(int i = 0; i <= n; i++)
        {
            while(!s.empty() && ( i==n or heights[s.top()] >= heights[i] ) )
            {
                // We have found the right smaller for the 
                // current s.top()
                int curr = heights[s.top()];
                s.pop();
                
                // If stack is empty, then we have 
                if(s.empty())
                    width = i;
                else width = i - s.top() - 1;
                
                area = max(area, (long long)width * curr);
            }
            s.push(i);
        }
        return area;
    }
};
