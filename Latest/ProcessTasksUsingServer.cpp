class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue< array<long,3>,vector<array<long,3>>, greater<array<long,3>>> busy;
        
        priority_queue<array<long,2>, vector<array<long,2>>,greater<array<long,2>>> free;
        for(int i = 0; i < servers.size(); i++)
        {
            free.push({servers[i], i});       
        }
        
        int time = 0;
        vector<int> res;
        for(int t = 0; t < tasks.size(); t++)
        {
            time = max(time, t);
            while (!busy.empty() and busy.top()[0] <= time or free.empty() )
            {
                auto [time1, w, i] = busy.top();
                busy.pop();
                if(free.empty())time = time1;
                free.push({w, i}); // 1 is weight, 2 is index
            }
            if(!free.empty())
            {
                auto [w,i] = free.top();
                free.pop();
                busy.push({time + tasks[t], w, i});
                res.push_back(i);
            }
            
        }
        
        return res;
    }
};
