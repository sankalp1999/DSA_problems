// problem https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/


#include <bits/stdc++.h>
using namespace std;
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
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n+1]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n+1, -1);
	vector<int> low(n+1, -1); 
	vector<int> vis(n+1, 0);
	vector<int> isArticulation(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj, isArticulation); 
	    }
	}
	
    int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int node;
		cin >> node;
		if(isArticulation[node])
		{
			int edges = adj[node].size();
			cout << "Satisfied " << edges << endl;
		}
		else cout << "Not Satisfied" << endl;
	}
	
	return 0;
}
