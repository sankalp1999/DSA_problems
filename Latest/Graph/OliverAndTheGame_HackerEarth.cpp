#include <bits/stdc++.h>
using namespace std;

// Most likely arrays and strings
// Most likely arrays sand st
void dfs(vector<int>& intime, vector<int>& outtime, vector<vector<int>>& adj ,int& time, int src, vector<int>& visited)
{
    time++;
    intime[src] = time;
    visited[src] = 1;
    for(int child : adj[src])
    {
        if(!visited[child])
        {
            dfs(intime,outtime,adj,time, child, visited);
        }
    }
    time++;
    outtime[src] = time;
}


int main()
{   

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1,vector<int>());
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> intime(n + 1, 0);
    vector<int> outtime(n + 1, 0);
    vector<int> visited(n + 1, 0);
    int time = 0;
    for(int i = 1; i <= n; ++i)
    {   
        if(!visited[i])
        {
            dfs(intime, outtime, adj, time, 1, visited);
            break;
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int w, x, y;
        cin >> w >> x >> y;
        if(w == 1)swap(x,y);
            if(intime[x] < intime[y] and outtime[x] > outtime[y])
            {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        
    }
  
}
