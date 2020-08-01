/*
We have to make choice whether to pick an element in our sequence or not.
For that, we maintain a dp array with the initial values. This is useful to preserve the sums till certain positions.

We use for loops, one to check till a certain position and other to iterate. We then compare i and j.
If arr[i] < arr[j], then we can increase our sum. Now, arr[i] has the optimal sum till that position. We can either
add v[i] or start a new subsequence from arr[i].

This question is similar to longest increasing subsequence.



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

	    for(int i = 0; i < n; i++)
	    {
	        cin >> v[i];
	    }
       
       long long int sum = 0;
       vector<int> arr(n, 0);
       for(int i = 0; i < n; i++)
       {
           arr[i] = v[i];
       }
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < i; j++)
           {
               if(v[j] < v[i])
               {
                   arr[i] = max(arr[i], arr[j] + v[i]); // Either start a new subsesquence or contribute to whatever we have till j
               }
           }
       }
       cout << *max_element(arr.begin(), arr.end()) << endl;
       
	}
	return 0;
}
