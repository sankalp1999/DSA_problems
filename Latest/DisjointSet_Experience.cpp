#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int n = 2e5 + 1;
int parent[n];
int rank1[n];
long long int sum[n];
int extra[n]; 

// This is to hold the extra points that are already there in that set. Since new points are added to parent
// while traversing from that element, we can subtract the extra points.

void init()
{
	for(int i = 0; i < n; i++)
	{
		parent[i] = i;
		rank1[i] = 0;
		sum[i] = 0;
		extra[i] = 0;
	}
}

int find(int a)
{
	if(a == parent[a])
		return a;
	return find(parent[a]);
}

int get(int a)
{
	long long int sum1 = 0;
	while(a != parent[a])
	{
		sum1 += sum[a] - extra[a];
		a = parent[a];
	}
	return sum1 + sum[a]  ;
}

void union1(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b)return;
	if(rank1[a] > rank1[b])// b go and join a 
	{
		parent[b] = a;
		extra[b] = sum[a];
 	}
	else if(rank1[b] > rank1[a])
	{
		parent[a] = b;
		extra[a] = sum[b];
	}
	else
	{	
		parent[b] = a;
		extra[b] = sum[a];
		rank1[a]++;
	}
}



int main() {
	
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, m;
	cin >> n >> m;
	init();
	while(m--)
	{
		string todo;
		cin >> todo;
		if(todo == "add")
		{
			// Don't use parent array. Use find operation.
			int par, add;
			cin >> par >> add;
			par = find(par);
			sum[par]+=add;
			
		}
		else if(todo == "join")
		{
			int a, b;
			cin >> a >> b;
			union1(a,b);
		}
		else if(todo == "get")
		{
			int temp;
			cin >> temp;
			cout << get(temp) << endl;
		}
	}
}
// Add reflects in all nodes.
// But previous xp does not add to new players
// How to solve this? What to modify?


