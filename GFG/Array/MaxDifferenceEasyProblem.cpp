#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for(int i =0 ; i < n; i++)
        {
            cin >> v[i];
        }
        int min_so_far = v[0];
        int max_diff =  -1;
        for(int i = 1; i < n; i++)
        {
            max_diff = max(max_diff, v[i] > min_so_far ? v[i] - min_so_far : -1);
            min_so_far = min(min_so_far, v[i]);
        }
        cout << max_diff << endl;
    }
	return 0;
}
