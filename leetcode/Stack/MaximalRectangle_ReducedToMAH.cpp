/*
We apply the MAH function by compressing the binary matrix into a 1d array row by row.
If the ground is 0, then we take that entry as zero as a building cannot fly. 
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
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.empty())return 0;
        vector<int> compress(matrix[0].size(),0);
        int curr_max = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == '0')
                {
                    compress[j] = 0;
                }
                else compress[j] += 1;
            }
            curr_max = max(curr_max, largestRectangleArea(compress));
        }        
        return curr_max;
    }
};
