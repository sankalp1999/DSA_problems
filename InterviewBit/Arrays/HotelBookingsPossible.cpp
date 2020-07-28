/*
This solution is based on the greedy approach which is 
used to find the minimum number of rooms required
to schedule all the bookings or interviews etc.
*/
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    vector<pair<int,int>> v;
    for(int i = 0; i < arrive.size(); i++)
    {
        v.push_back({arrive[i], depart[i]});
    }
    sort(v.begin(), v.end());
    int start, end;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].first == v[i].second)continue;
        if(!pq.empty() && pq.top() <= v[i].first) // Not overlapping. No new room required.
        {
            pq.pop();
        }
        pq.push(v[i].second); // Get the earliest finish time.
    }
    // cout << pq.size() << endl;
    if(pq.size() > K)return false;
    else return true;
    
}
