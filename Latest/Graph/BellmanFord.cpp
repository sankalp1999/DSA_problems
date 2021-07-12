// Check for overflow and ofcourse dist[source] = 0	

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    int dist[n];
	    for(int i = 0; i < n; i++)
	    {
	        dist[i] = 1e8 + 1;
	    }
	    dist[0] = 0;
	    for(int i = 0; i < n - 1; i++)
	    {
	        for(int j = 0; j < edges.size(); j++)
	        {
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int w = edges[j][2];
	            if(dist[u] + w < dist[v])
	            {
	                dist[v] = dist[u] + w;
	            }
	        }
	    }
	    int flag = 0;
	    for(int j = 0; j < edges.size(); j++)
	    {
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int w = edges[j][2];
	            if(dist[u] + w < dist[v])
	            {   
	                flag = 1;
	                dist[v] = dist[u] + w;
	            }
	    }
	    return flag == 1    ;
	}
