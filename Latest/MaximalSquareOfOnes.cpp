class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int square[n][m];
        memset(square, 0, sizeof square);
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = m - 1; j >= 0; j--)
            {
                if(matrix[i][j] == '1')count++;
                else count = 0;
                square[i][j] = count;
            }
        }
        int max_area = 0;
        for(int i = 0; i < n ;i++)
        {
            for(int j = 0; j < m; j++)
            {
                // check
                int width = square[i][j];
                for(int down = i; down < n; down++)
                {
                    width = min(width, square[down][j]);
                    int length = down - i + 1;
                    if(length == width)
                    max_area = max(max_area, width * length);
                }
            }
        }
        return max_area;
    }
};
