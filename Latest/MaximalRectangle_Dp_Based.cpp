// Time complexity O(N * M * N) since we are going down from each cell

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
        {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int rect[row + 1][col + 1];
        memset(rect, 0, sizeof rect);
      
        // Get the width in that row from right to left coz we are gonna process
        // from left to right.
        for(int i = 0; i < row; i++)
        {
            if(matrix[i][col - 1] == '1')
            {
                rect[i][col - 1] = 1;
            }
            for(int j = col - 2; j >= 0; j--)
            {
                if(matrix[i][j] == '1')
                rect[i][j] = rect[i][j + 1] + 1;
                else
                {
                    rect[i][j] = 0;
                }
            }
        }
      
        
        
        int max_area = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                int width_min = 201;
                for(int k = i; k < row; k++) // For each cell, we go down (vertically) and check the min width thanks to our 
                                             // lower width vertically down neighbours.
                {
                    width_min = min(rect[k][j], width_min);
                    max_area = max(max_area, width_min * (k - i + 1) );
                }
                
            }
        }
        return max_area;
    }
};
