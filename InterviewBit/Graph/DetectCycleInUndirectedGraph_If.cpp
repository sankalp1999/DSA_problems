
/*
Explanation
We can use DFS to detect cycle in an undirected graph in O(V+E) time. We do a DFS traversal of the given graph. 
For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited 
and u is not parent of v, 
then there is a cycle in graph. 
If we don’t find such an adjacent for any vertex, 
we say that there is no cycle. 
The assumption of this approach is that there are no parallel edges between any two vertices.

*/


bool dfs(vector<vector<int>>& adj, vector<int>& visited, int source, int parent)
{
    visited[source] = 1;
    for(int child : adj[source])
    {
   
        if(!visited[child])
        {
            if(dfs(adj, visited, child, source))
            return true;
        }
        else if(child != parent ) // Main check to see if it is not parent.
        {
            return true;
        }
       
    }
    return false;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    
    
    vector<vector<int>>adj(A + 1, vector<int>());
    for(int i = 0; i < B.size(); i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    vector<int> visited(A + 1, 0);
    
    for(int i = 1; i <= A; i++) // Graph may not be connected
    {
        if(!visited[i] && dfs(adj, visited, i, -1))
        {
            return 1;
        }
    }
    return 0;
}
