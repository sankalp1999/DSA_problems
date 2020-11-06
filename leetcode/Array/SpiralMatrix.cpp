class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;
        if(matrix.empty())
        {
            return res;
        }
        
        
        int n, m;
        n = matrix.size();
        m = matrix[0].size();
       
        int row_start = 0;
        int row_end = n - 1 ;
        int col_start = 0;
        int col_end = m - 1 ;
    
        
    while(row_start <= row_end && col_start <= col_end)
    {
        for(int i = col_start; i <= col_end; i++)
        {
            int ele = matrix[row_start][i];
            res.push_back(ele);
        }
        row_start++;
        if(row_start>row_end)break;
        
        for(int i = row_start; i <= row_end; i++)
        {
            int ele = matrix[i][col_end];
            res.push_back(ele);
        }
        col_end--;
        if(col_start>col_end)break;
        
        
        for(int i = col_end; i >= col_start; i--)
        {
            int ele  = matrix[row_end][i] ;
            res.push_back(ele);
        }
        row_end--;
        
        for(int i = row_end; i >= row_start ;i-- )
        {
            int ele = matrix[i][col_start];
            res.push_back(ele);
        }
        col_start++;
    }
        return res;
    }
};
