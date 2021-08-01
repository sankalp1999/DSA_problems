class Solution {
public:
    vector<int> rank1;
    vector<int> parent;
    
    void init(int n)
    {
        for(int i = 1; i <= n; i++)
            parent[i] = i, rank1[i] = 1;
    }
    int find(int a)
    {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    void union1(int a, int b)
    {
        a = find(a);
        b = find(b);
        if(a == b)return;
        if(rank1[a] < rank1[b])
        {
            parent[a] = b;
        }
        else if(rank1[b] < rank1[a])
        {
            parent[b] = a;
        }
        else
        {
            parent[b] = a;
            rank1[a]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges)     {
        int n = edges.size();
        rank1.resize(n+1);
        parent.resize(n+1);
        init(n);
        vector<int> temp;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(find(u) != find(v))
            {
                union1(u,v);
            }
            else temp = {u,v};
        }
        return temp;
    }
};
