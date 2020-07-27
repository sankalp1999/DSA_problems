/*
Main idea
We want the earliest time after some end time when we can 
start a meeting. We would like to do the scheduling of the 
meetings in a chronological order so it makes sense 
to sort according to start times.(It makes life easier also)
*/
int Solution::solve(vector<vector<int> > &A) {
    
        vector<pair<int,int>> v;
        for(int i = 0; i < A.size(); i++)
        {
            v.push_back({A[i][0], A[i][1]});
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>> minheap;


        for(int i = 0; i < v.size(); i++)
        {
            if(!minheap.empty() && minheap.top() <= v[i].first)
            {
                minheap.pop(); // Which don't overlap, we don't need to open a room.
            }
            minheap.push(v[i].second); // Store the end times in a minheap to get 
                                       // nearest end time in O(1)
        }
        
        return (int)minheap.size() ;
    
}
