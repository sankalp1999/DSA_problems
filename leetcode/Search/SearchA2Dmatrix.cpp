class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty())
            return false;
        if(matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while(j >= 0 && i < m)
        {   
            
            if(target < matrix[i][j])
                j--; // Go left i.e decreased your value
            else if(target > matrix[i][j])
            {
                i++; // Go down i.e increase your value
            }
            else if(target == matrix[i][j])return true;
        }
        return false;
        
    }
};
