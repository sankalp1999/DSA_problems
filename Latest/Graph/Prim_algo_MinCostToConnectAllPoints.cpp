// Time Complexity of Prims: O(E+ V log V)
// Time Complexity of Kruskal: O(E log E + E)
// Hence Kruskal takes more time on dense graphs.

// Kruskal gives TLE since it takes more time on dense graphs.

class Solution {
public:
    
    int dist(vector<int>& p1, vector<int>& p2) // Compute manhattan distance
    {
        return abs(p1[0] - p2[0]) + abs(p2[1] - p1[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        // we already have the vertices.
        // No need to construct a graph explicitly 
        // coz the edge weight is manhattan distance already
        int n = points.size();
        vector<pair<int,int> > adj[n];
        int count = 0;
        for(int i =0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                count++;
                int w = dist(points[i], points[j]);
                adj[i].push_back({j,w} ); // Undirected graph
                adj[j].push_back({i,w});
            }
        }
        vector<int> parent(n);
        vector<int> key(n,1e8);
        vector<bool> mstSet(n, false);
        priority_queue< array<int,2>, vector<array<int,2>>, greater<array<int,2>> > pq ;
        key[0] = 0;
        parent[0] = -1;
        pq.push({0,0}); // To find the minimal key or the node that provides 
                        // the minimum weight edge.
        int cost = 0;
        while(!pq.empty()) // This is not clear. Idk why 0 to N - 1 does not work although it should.
        {
            auto [w, u] = pq.top();
            pq.pop();
            
            mstSet[u] = true;
            for(auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;
                if(mstSet[v] == false and weight < key[v])
                {
                    parent[v] = u;
                    key[v]= weight;
                    pq.push({key[v],v});
                }
            }
        }
        for(int i = 1; i < n; i++)
        {
            cost += key[i];
        }
        
        return cost;
    }
};
