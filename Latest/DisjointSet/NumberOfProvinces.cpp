// Be careful with indexing.

class Solution {
public:
    
    int find(int a, vector<int>& parent)
    {   if(a == parent[a])
            return a;
        return parent[a] = find(parent[a], parent);
    }
    
    void union1(int a, int b, vector<int>& parent, vector<int>& rank)
    {
        a = find(a,parent);
        b = find(b,parent);
        if(a == b)return;
        if(rank[a] < rank[b])
        {
            parent[a] = b;
        }
        else if(rank[b] < rank[a])
        {
            parent[b] = a;
        }
        else
        {
            parent[b] = a;
            rank[a]++;
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj[0].size();
        vector<int> rank(n + 1, 1);
        vector<int> parent(n + 1, 0);
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(adj[i-1][j-1] == 1 and find(i,parent)!=find(j,parent))
                {
                    union1(i,j,parent,rank);
                }
            }
        }
        int count = 0;
        for(int i = 1; i <= n; i++)
        {
            if(parent[i] == i)
            {
                count++;
            }
        }
        return count;
        
    }
};
