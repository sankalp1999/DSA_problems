#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int n = 1e3 + 10;
int parent[n];
map<int,int> size;

void init()
{
    for(int i = 1 ; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int a)
{
    return parent[a] == a ? a : find(parent[a]);
}

void union1(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)return;
    if(size[a] > size[b])swap(a,b);
    // Now a  < b
    parent[a] = b;
    size[b] += size[a];
    size[a]=0;
}



int main()
{
	init();
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int n1 = n;
	vector<pair<int,int>> old;
    for(int i = 0; i < n - 1; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	int para, parb;
    	para = find(a);
    	parb = find(b);
    	if(para != parb)union1(a,b);
    	else old.push_back({a,b});
    }
   // We don't need to add these edges since they are already connected.
   vector<int> temp;
   // Get the disconnected components and make connections between them.
   for(int i = 1; i <= n; i++)
   {
   	if(parent[i] == i) // i.e leader of the set
   	{
   		temp.push_back(i);
   	}
   }
   cout << (int)temp.size() - 1 << endl;
  for(int i = 0; i < (int)temp.size() - 1; i++)
  {
  	cout << old[i].first << " " << old[i].second << " " << temp[i] << " " << temp[i+1] << endl;
  }
    
    
    
}
