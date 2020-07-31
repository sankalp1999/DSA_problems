/*
At any point of time, we need to add ropes of minimum length.
So, heap comes into the play.
Add all the elements in the heap.
Now to keep track of newly generated minimum elements, use heap.
Add top 2 minimum number and add it to result. When heap size is less than 2, exit the loop.
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
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        priority_queue<int,vector<int>,greater<int>> pq; // Minheap
        
        long long int sum  = 0;
        
        for(int i = 0; i < n; i++)
        {
            pq.push(v[i]);
        }
        
        long long int temp = 0;
        
        while(pq.size() >= 2)
        {
            temp = pq.top();
            pq.pop();
            temp += pq.top();
            pq.pop();
            pq.push(temp);
            sum += temp;
        }
        
        cout << sum << endl;
    }
	return 0;
}
