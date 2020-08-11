/*
The area that can be bounded will be less than or equal to height of current cell.
The width will expand till we have that amount of height, right?
Same goes for the left side.
So, we use stack to find nearlest left element and nearest right element.
We add indices inside the stack so that we can calculate the width.
Then, we can easily calculate (nsr[i] - nsl[i] - 1) * height[i]
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     
        
        stack<int> s;
        vector<int> nsl;
        nsl.push_back(-1);
        s.push(0);
        
        // For left side
        for(int i = 1; i < heights.size(); i++)
        {
            if(s.empty())
            {
                nsl.push_back(-1);
            }
            else 
            {
                while(!s.empty() && heights[s.top()] >= heights[i])
                {
                    s.pop();
                }
                if(s.empty())nsl.push_back(-1);
                else
                    nsl.push_back(s.top());
            }
            s.push(i);
        }
        
        // For right side
        int n = heights.size();
        vector<int> nsr;
        nsr.push_back(n);
        
        // Emptying the previous stack for later use
        while(!s.empty())s.pop();
        
        s.push(heights.size() - 1);
        int filler = n;
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            if(s.empty())
            {
                nsr.push_back(filler);
            }
            else 
            {
                while(!s.empty() &&  heights[s.top()] >= heights[i])
                {
                    s.pop();
                }
                if(s.empty())nsr.push_back(filler);
                else
                    nsr.push_back(s.top());
            }
            s.push(i);
        }
        reverse(nsr.begin(), nsr.end());
        
        int res = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            int width = (nsr[i] - nsl[i] - 1);
            res = max(res, width * heights[i]);
        }
        
        return res;
        
  
        
    }
};
