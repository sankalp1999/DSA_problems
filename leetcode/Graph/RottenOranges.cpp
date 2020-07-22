/*
Multi-source BFS
We add all the oranges which are rotten initially because all of them will start
affecting the other oranges.
BFS guarantees to give the shortest path because it treats the neighbours first.
The number of levels of the bfs indicates the minimum number of minutes.

In the end, we check if any grid cell is still fresh because of any zero between. 
If so, return -1;

O(N or N^2) time complexity depending on what you count the grid as.
*/


class Solution {
public:
    
    bool isValid(int n, int m, int x, int y, vector<vector<int>>& grid)
    {
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y]== 0 || grid[x][y] == 2)
        {
            return false;
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
    // Shortest indicates we need to use BFS
    // Since bfs finds the shortest path
        
    // The number of levels is the answer
        int dx[] = {0,1,0,-1}; // Transition vectors
        int dy[] = {1,0,-1,0};
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 2)
                q.push(make_pair(i,j)); // start search with all the rotten oranges simultaneously
                if(grid[i][j] == 1)fresh++;
            }
        }
        if(fresh==0)return 0;
        
        // Multi-source BFS
        int level = 0;
        while(!q.empty())
        {
            int count = q.size();
             level++;
            while(count--)
            {
                auto top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                for(int i = 0; i < 4; i++)
                {
                    if(isValid(n, m, x + dx[i], y + dy[i], grid))
                    {
                        grid[x+dx[i]] [y + dy[i]] = 2;
                        q.push({x+dx[i], y + dy[i]});
                    }
                }
            }
           
        }
        
        // Check if fresh oranges are still there.
        
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)return -1;
            }
        }
        return level-1;
    
    
    }
};
