/*
If so, the graph is bipartite if and only if the two ends of each edge must have opposite colors. Therefore, we could just start with standard BFS to traverse the entire graph and

color neighbors with opposite color if not colored, yet;
ignore neighbors already colored with oppsite color;
annouce the graph can't be bipartite if any neighbor is already colored with the same color.
*/


class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {

    queue<int> q;
    vector<int> color(adj.size(), -1);
    vector<int> visited(adj.size(), 0);
    
    /* Some of the graph vertices can be absent so used a for loop */
    for(int i = 0; i < adj.size(); i++) 
    {
        if(adj[i].empty())continue;
        
        if(visited[i])continue;
        q.push(i);
        visited[i] = 1;
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            for(int child : adj[top])
            {
                visited[child] = 1;
                if(color[child] == -1)
                {   
                    color[child] = color[top]^1; // Color with different color
                    q.push(child);
                }
                else if(color[top] == color[child])return false; // If already colored and different color
            }
        }
    }
        return true;
    }
};
