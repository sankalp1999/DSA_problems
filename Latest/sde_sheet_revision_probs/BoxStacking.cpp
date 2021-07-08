static bool compare(vector<int>& a, vector<int>& b)
    {
        int area = a[0] * a[1];
        int area2 = b[0] * b[1];
        return area > area2;
    }
    
    int maxHeight(int height[],int width[],int length[],int n)
    {
        vector< vector<int> > temp;
        for(int i = 0; i < n; i++)
        {
            vector<int> v,v2,v3;
            v = {max(height[i],length[i]), min(height[i],length[i]), width[i]};
            temp.push_back(v);
            v2 = {max(length[i],width[i]), min(width[i],length[i]), height[i] };
            temp.push_back(v2);
            v3 = {max(width[i],height[i]), min(width[i], height[i]), length[i]};
            temp.push_back(v3);
        }
        sort(temp.begin(), temp.end(), compare);
        vector<int> dp;
        for(int i = 0; i < temp.size(); i++)
        {
            dp.push_back(temp[i][2]);
        }
        n = temp.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(temp[j][0] > temp[i][0] and temp[j][1] > temp[i][1])
                {
                    dp[i] = max(dp[i], dp[j] + temp[i][2]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
        
    }
