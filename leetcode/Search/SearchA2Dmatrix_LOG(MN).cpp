/*
Since the first element of each row is larger than the 
last element of the previous row, this means that 
each row is sorted (since it is provided that each row is already 
sorted)
Hence, we run a binary search on the whole 2D array

Time complexity:
O ( log ( M * N )) 
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int high = m * n - 1;
        int low = 0;
        while(low <= high)
        {
            int mid = (high - low)/2 + low;
            int row = mid/n;
            int col = mid%n;
            if(target < matrix[row][col])
            {
                high = mid - 1;
            }
            else if(target > matrix[row][col])
            {
                  low = mid + 1;
            }
            else if(target == matrix[row][col])
            {
                return true;
            }
        }
        return false;
    }
};
