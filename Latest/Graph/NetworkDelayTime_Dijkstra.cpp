class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // k to all nodes.
        // Assuming the signal will take the shortest path
        // and since the edges with weights are given, probably
        // dijkstra should be used.
        vector< vector < pair <int,int> > > adj(n + 1, vector<pair<int,int>>());
        for(int i = 0; i < times.size(); i++)
        {
            int a = times[i][0];
            int b = times[i][1];
            int w = times[i][2];
            adj[a].push_back({b,w});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int prevWeight = top.first;
            int prevNode = top.second;
            
            for(auto nextNode: adj[prevNode])
            {
                int node = nextNode.first;
                int w = nextNode.second;
                if(prevWeight + w < dist[node])
                {
                    dist[node] = prevWeight + w;
                    pq.push({dist[node], node});
                }
            }
        }
        long int maxi = 0;
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX)return -1;
            maxi = max(maxi, (long)dist[i]);
        }
        return maxi;
        
    }
};
