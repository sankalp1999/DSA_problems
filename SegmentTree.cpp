#include <bits/stdc++.h>
using namespace std;

int a[100005], seg[4 * 100005];

void build(int curr, int low, int high)
{
    if(low == high) // If only one element left
    {
        seg[curr] = a[low];
        return;
    }
    int mid = (high - low)/2 + low;
    
    // Postorder traversal
    build(2 * curr + 1, low, mid);
    build(2 * curr + 2, mid + 1, high);

    // This is the place for the functions while backtracking
    seg[curr] = min(seg[2 * curr + 1], seg[2 * curr + 2]);
}

int query(int curr, int low, int high, int l, int r)
{
    if(low >= l && high <= r ) // completely lies
    {
        return seg[curr];
    }   
    if(high < l || low > r)// does not lie in the interval
        return INT_MAX;

    // Overlaps partially so go towards left and right
    int mid = (high - low)/2 + low;
    int left = query(2 * curr + 1, low, mid, l, r);
    int right = query(2 * curr + 2, mid + 1, high, l, r);
    return min(left, right);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(0, 0, n -1);
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << endl;
    }
    return 0;
}
