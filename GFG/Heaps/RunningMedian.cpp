#include <bits/stdc++.h>

using namespace std;



int main() {
	int t;
	cin >> t;
	priority_queue<int,vector<int>,greater<int>> minheap;
	priority_queue<int> maxheap;
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    if(maxheap.empty() && minheap.empty())
	    {
	        maxheap.push(n);
	        cout << maxheap.top() << endl;
	        continue;
	    }
	    if(n > maxheap.top() && minheap.empty())
	    {
	        minheap.push(n);
	        if(minheap.size() == maxheap.size())
	        {
	            cout << (minheap.top() + maxheap.top())/2 << endl;
	        }
	        else
	        {
	            cout << maxheap.top() << endl;
	        }
	        continue;
	    }
	    
	    if(n <= maxheap.top())
	    {
	        maxheap.push(n);
	    }
	    else
	    {
	        minheap.push(n);
	    }
	    if((int)maxheap.size() - (int)minheap.size() >= 2)
	    {
	                int top = maxheap.top();
	                maxheap.pop();
	                minheap.push(top);
	    }
	    else if((int)minheap.size() - (int)maxheap.size() >= 2)
	    {
	              int top = minheap.top();
	                minheap.pop();
	                maxheap.push(top);
	    }
	    if(maxheap.size() == minheap.size())
	    {
	          cout << (minheap.top() + maxheap.top())/2 << endl;
	    }
	    else if(maxheap.size() > minheap.size())
	    {
	        cout << maxheap.top() << endl;
	    }
	    else cout << minheap.top() << endl;
	    
	    
	}
	return 0;
}
