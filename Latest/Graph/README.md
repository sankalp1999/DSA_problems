

Bridges
```

insertion time or discovery time of a node < lowest id of all reachable nodes of nei, this means there was no backedge from nei to an anscestor of node 
and thus (node -> nei) is a bridge.

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
                
                // This location is important. We check after dfs of child is complete.
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
    
    ```
