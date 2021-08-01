

Kosaraju
1. Do a dfs and store nodes in a stack
2. Take transpose of graph (and reset visited)
for(auto it : adj[node])
{
	transpose[it].push_back(node);
}
3. Do a dfs on nodes popped by stack to count components.

Intuition:
Suppose we have a -> b <- c --> d as SCC
Here, a can go to b and c can go to b. So our normal method to find components will fail since 
we go from a to b and c to b.

In our stack

a will be above b.
c will also be above b because their dfs will finish later(stack stores time of finishing dfs)

a <- b -> c <- d
So when we follow order of stack, a will visit only a in transpoe.
c will visited only c. Then b can't visit both of them since already visited.


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
  
  Articulation Point
  ```
  void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++;
    int children = 0; 
    for(auto child: adj[node]) {
        // Parent is which called
		// node is curretnly being visited
		// child is the neighbours of node
		if(child == parent) continue;
        
        if(!vis[child]) {
            dfs(child, node, vis, tin, low, timer, adj, isArticulation); 
            // Did you see a backedge to my ancestor?
			// If yes, then you are connected and safe without me
			low[node] = min(low[node], low[child]); 
	        
			children++;  // root children

            if(low[child] >= tin[node] && parent != -1) {
                isArticulation[node] = 1; 
            }
        } else {
            low[node] = min(low[node], tin[child]); 
        }
    }
    
    if(parent == -1 && children > 1) {
        isArticulation[node] = 1; 
    }
}
```    
    
    
    
