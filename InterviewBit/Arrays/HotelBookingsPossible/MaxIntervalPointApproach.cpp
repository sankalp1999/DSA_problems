/*
This approach uses the max interval point approach.
Just we interchange 'A' and 'B' to handle the overlapping case
1 2 3 5
2 3 4 6
(1,B) (2,A) (2,B) (3,A) we want 2A before 2B i.e we want the end time before the start time of next interval.
Carefully, deciding that helps to solve the problem.

*/



bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    // Finding the max interval point approach
    
    vector<pair<int,char>> v;
    for(int i = 0; i < arrive.size(); i++)
    {
        v.push_back({arrive[i], 'B'});
    }
    for(int i = 0; i < arrive.size(); i++)
    {
        v.push_back({depart[i], 'A'});
    }
    int max_interval = 0;
    int count = 0;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        
        if(v[i].second == 'B') // Active  guest +1
        {    count++;
            max_interval = max(max_interval, count);
        }
        else if(v[i].second == 'A') // Guest departed.
        {
            count--;
        }
    
    }
    if(max_interval > K)return 0;
    else return 1;
    
}
