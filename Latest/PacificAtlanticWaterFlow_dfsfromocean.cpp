class Solution {
public:
    
    bool isValid(int x, int y, vector<vector<int>>& heights)
    {   
        int n = heights.size();
        int m = heights[0].size();
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<int>>& visited)
    {
        if(visited[x][y])return;
        visited[x][y] = 1;
        
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        
        int temp = heights[x][y];    
            
        for(int i = 0; i < 4; ++i)
        {
            int x1 = x + dx[i];
            int y1  = y + dy[i];
            if(isValid(x1,y1,heights) and heights[x1][y1] >= heights[x][y])
            {
                heights[x][y] = 0;
                dfs(heights, x1, y1, visited);
                heights[x][y] = temp;
            }
        }
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> visited2(n, vector<int>(m, 0));
        
        int i = 0; int j =0;
        for(int i = 0; i < m; i++)
        {
            dfs(heights, 0, i, visited);
        }
        for(int i = 0; i < n; i++)
        {
            dfs(heights, i, 0, visited);
        }
        for(int i = 0; i < m; i++)
        {
            dfs(heights, n - 1, i, visited2);
        }
        for(int i = 0; i < n; i++)
        {
            dfs(heights, i,  m - 1, visited2);
        }
        int count = 0;
        vector<vector<int>> res;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visited[i][j] and visited2[i][j])
                {
                    vector<int> temp = {i, j};
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
