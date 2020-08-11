/*
We find the maximum height which can be bounded. 
By observation, it can be found out that that maximum height in which current element is drowned or part of 
is given by min(MaxL,MaxR) - height. We get the trapped water by subtracting current building height from 
the max covering height.
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int> v(n,0);
	    for(int i = 0; i < n; i++)
	    {
	        cin >> v[i];
	    }
	    
	    
	    vector<int> maxL;
	    vector<int> maxR;
	    maxL.push_back(v[0]);
	    for(int i = 1; i < n; i++)
	    {
	        maxL.push_back(max(maxL.back(), v[i]));
	    }
	    
        maxR.push_back(v.back());
        for(int i = n - 2; i >= 0; i--)
        {
            maxR.push_back(max(maxR.back(), v[i]));
        }
        reverse(maxR.begin(), maxR.end());
        
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res += min(maxR[i],maxL[i]) - v[i];
        }
        cout << res << endl;
	    
	}
	return 0;
}
