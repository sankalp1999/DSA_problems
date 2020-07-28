/*
O(N log N) solution. (Got confused in this question)
We sort the array. This way, we satisfy the A[i]<= A[j] constraint.
Now, we have to find max j - i. For that, we keep track of minimum ith index 
visited so far and keep track of (current - min) since our current element is the jth entry and previous entries
can be treated as ith entries.
*/



typedef pair<int,int> pii;
int Solution::maximumGap(const vector<int> &A) {
    
    vector<pair<int,int>> temp;
    for(int i = 0; i < A.size(); i++)
    {
        temp.push_back({A[i], i});
    }
    sort(temp.begin(), temp.end());
    int max_diff = 0;
    int index = INT_MAX;
    int res = 0;
    for(int i = 0; i < temp.size() ; i++)
    {
        index = min(index, temp[i].second);
        res = max(res, temp[i].second - index);
    }
    return res;
    
}
