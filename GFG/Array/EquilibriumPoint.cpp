/*
Get full sum of the array.
Then maintain a running sum to obtain the sum of the right part of the array.
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
	    vector<int> v(n + 1);
	    long long int sum = 0;
	    for(int i = 1; i <= n; i++)
	    {
	        cin >> v[i];
	        sum += v[i];
	    }
	    
	    long long int ssum = 0;
	    int flag = 0;
	    for(int i = 1; i <= n; i++)
	    {
	        
	        if(ssum == sum - v[i] - ssum)
	        {
	            cout << i << endl;
	            flag = 1;
	            break;
	        }
	        ssum += v[i];
	       
	    }
        if(flag == 0)
        {
            cout << -1 << endl;
        }
	}
	return 0;
}
