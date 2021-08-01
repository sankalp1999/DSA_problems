

// Problem https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
public:
    
    void dfs(int src, int par, vector<vector<int>>& adj, vector<int>& visited, vector<int>& disc, vector<int>& low, vector<vector<int>>& bridge, int& time)
    {
        visited[src] = 1;
        disc[src] = low[src] = time++;
        
        for(auto child : adj[src])
        {   
            if(child == par)continue;
            if(visited[child] == 0)
            {
                dfs(child,src,adj,visited,disc,low,bridge,time);
                low[src] = min(low[src],low[child]); 
                // did you see a smaller link or backedge?
                 if(low[child] > disc[src])
                 {
                    vector<int> temp = {child,src};
                    bridge.push_back(temp);
                 }
            }
            else if(visited[child])
            {
                low[src] = min(low[src], disc[child]);
                
            }
            
        }
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Find the bridges.
        vector<vector<int>> adj(n,vector<int>());
        for(int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        vector<int> disc(n,0);
        vector<int> low(n,0);
        vector<vector<int>> bridge;
        int time = 0;
        dfs(0,-1,adj,visited,disc,low,bridge,time);
        return bridge;
    }
};
