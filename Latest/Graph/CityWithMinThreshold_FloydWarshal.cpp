class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int mod = 1e9;
        vector<vector<int>> dp(n+1,vector<int>(n+1,mod));
        vector<vector<int>> adj(n+1,vector<int>(n+1,0));
        
        for(int i = 0; i < (int)edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u][v] = w;
            adj[v][u] = w;
            dp[u][v] = w;
            dp[v][u] = w;
        }
        for(int i = 0; i < n; i++)dp[i][i] = 0;
        
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {   
                
                for(int j = 0; j < n; j++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int res = 1e9 + 1;
        int id = -1;
        for(int i = 0; i < n; i++)
        {
            int countCity = 0;
            for(int j = 0; j < n; j++)
            {   
                if(i == j)continue;
                if(dp[i][j] <= distanceThreshold)
                {
                    countCity++;
                }
            }
            if(countCity <= res)
            {
                res = countCity;
                id = i;
            }
        }
        return id;
    }
};
