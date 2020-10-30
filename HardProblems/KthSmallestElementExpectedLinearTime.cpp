#include <bits/stdc++.h>
using namespace std;

/*
This solution uses randomized paritioning 
Expected Linear Time complexity
*/

void randomPartition(vector<int>& v, int l, int r) 
{ 
    int n = r-l+1; 
    int pivot = rand() % n; 
    swap(v[l], v[r - pivot]); 
} 

int partition(vector<int>& v, int left, int right)
{
    randomPartition(v,left,right); // Just swap the pivot with some other 
    // element in the range. This will randomize it a bit.
    int pivot = left;
    for(int i = left + 1; i <= right; i++)
    {
        if(v[i] <= v[pivot])
        {
            swap(v[i], v[++left]);
        }
    }
    swap(v[left], v[pivot]);
    return left;
    
}

int main() {
	int t;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int> v(n);
	    
	    for(int i = 0; i < n; i++)
	    {
	        cin >> v[i];
	    }
	    int k;
	    cin >> k;
	    k--; // 0 based indexing is followed
	    int left = 0;
	    int right = n - 1 ;
	    while(left <= right) // It's not binary search and in BS also, left == right
        //allowed
	    {
	        int pos = partition(v, left, right);
	        if(pos == k)
	        {
	            cout << v[pos] << endl;
	            break;
	        }
	        if(pos < k)
	        {
	            left = pos + 1;
	        }
	        else if(pos > k)
	        {
	            right = pos - 1;
	        }
	       
	    }
	    
	}
	return 0;
}