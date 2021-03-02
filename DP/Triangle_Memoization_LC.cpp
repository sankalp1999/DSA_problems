class Solution {
public:
    int cache[201][201];
  
    int dp(vector<vector<int>>& tri, int i, int j)
    {
        if(j == tri.size())
        {
            return 0;
        }
        if(cache[j][i] != -1)return cache[j][i];  
        
        return (cache[j][i] = tri[j][i] + min(dp(tri,i,j + 1), dp(tri,i+1,j + 1)) );
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
      memset(cache,-1,sizeof(cache));
        int j = 0;
        int i = 0;
        return dp(triangle, i, j);
    }
};