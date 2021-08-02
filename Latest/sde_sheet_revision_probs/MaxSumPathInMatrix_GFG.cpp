int maximumPath(int N, vector<vector<int>> Matrix)
    {
        for(int i = 1; i < N; i++)
        {   
            
            for(int j = 0; j < N; j++)
            {   
                int o = Matrix[i][j];
                Matrix[i][j] = Matrix[i-1][j] + o; // We need to use original value. Otherwise, Matrix[i][j] gets updated
                if(j-1>=0)
                {
                    Matrix[i][j] = max(Matrix[i][j], Matrix[i-1][j-1] + o);
                }
                if(j+1<N)
                {
                    Matrix[i][j] = max(Matrix[i][j], Matrix[i-1][j+1] + o);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < N; i++)
        {
            res = max(res, Matrix[N-1][i]);
        }
        return res;
    }
