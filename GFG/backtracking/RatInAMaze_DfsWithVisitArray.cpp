void dfs(int arr[][MAX], int n, vector<string>& res, int x, int y, string curr)
{
    if(x == n - 1 && y == n - 1)
    {
        res.push_back(curr);
        return;
    }
    
    if(x < 0 || x >= n || y < 0 || y >= n || arr[x][y] != 1)
    {
        return;
    }
    int earlier = arr[x][y];
    arr[x][y] = 2;
    
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    for(int i = 0; i < 4; i++)
    {
       int px = x + dx[i];
       int py = y + dy[i];
       string rn = "";
       
       if(i == 1)
       {
           rn += "D";
       }
       else if(i == 0)
       {
           rn += "R";
       }
       else if(i == 3)
       {
           rn += "U";
       }
       else if(i == 2)
       {
           rn += "L";
       }
       string temp = curr + rn;
       dfs(arr, n, res, px, py, temp);
    }
    arr[x][y] = earlier;
    
}


vector<string> printPath(int m[MAX][MAX], int n) {
    // What am i gonna do? Write a four direction dfs
    // if reach (n - 1, n - 1)
    // add to vector of strings.
    vector<string> res;
    if(m[n-1][n-1]==0)return res;
    
    int x, y;
    x = y = 0;
    string curr = "";
    dfs(m, n, res, x, y, curr);
    sort(res.begin(), res.end());
    return res;
}
