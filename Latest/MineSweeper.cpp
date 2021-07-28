class Solution {
public:
    bool isValid(int x, int y, int n, int m)
    {
        if(x < 0 or y < 0 or x >= n or y >= m)
            return false;
        return true;
    }
    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<int>>& visited)
    {
        if(board[r][c] == 'M')
        {
            board[r][c] = 'X';
            return;
        }
        int n = board.size();
        int m = board[0].size();
        
        // We will have to check all valid adjacent mines
        int dx[] = {0,1,0,-1,1,-1,1,-1};
        int dy[] = {1,0,-1,0,1,-1,-1,1};
        visited[r][c] = 1; 
        int num = 0;
        for(int i = 0; i < 8; i++)
        {
            int x1 = r + dx[i];
            int y1 = c + dy[i];
            if(isValid(x1, y1, n, m) and !visited[x1][y1])
            {
                if(board[x1][y1] == 'M')
                {
                    num++;
                }
            }
        }
        if(num > 0)
        board[r][c] = '0' + num;
        else if(num == 0)
        {       board[r][c] = 'B';
         
         for(int i = 0; i < 8; i++)
        {
            int x1 = r + dx[i];
            int y1 = c + dy[i];
            if(isValid(x1, y1, n, m) and !visited[x1][y1])
            {
                if(board[x1][y1] == 'M')continue;
                dfs(board, x1, y1, visited);
            }
        }
        }
    }
    
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        
        int r = click[0];
        int c = click[1];
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m));
        dfs(board, r, c, visited);
        return board;
    }
}; 
// click = [3, 0]

// [["E","E","E","E","E"],
//  ["E","E","M","E","E"],
//  ["E","E","E","E","E"],
//  ["E","E","E","E","E"]]
