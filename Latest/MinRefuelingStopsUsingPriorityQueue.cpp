class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if( stations.empty())
        {
            if(startFuel >= target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        priority_queue<int> pq;
        // While running, keep track of the max fuel stop. 
        // Use that to refill.
        
        // We try to go as far as we can. When finished, we check out the largest station
        // we have been to. No DP shit required here.
        int stops = 0;
        int curr = 0;
        int curr_Distance = 0;
        int dist = 0;
        for(int i = 0; i < stations.size(); i++)
        {
            curr += startFuel;
            cout << curr << endl;
            startFuel -= startFuel;
            // Keep refilling from previous stations. We need a while loop
            // since we cannot go beyond this point until we have enough fuel.
            // I was earlier making the mistake 
            // of just moving to next iteration and checking but in that 
            // case, we are moving forward and adding the fuel from later stations
            // where we can't reach lol!
            while(curr + startFuel < stations[i][0])
            {
                if(pq.empty())return -1;
                else 
                {
                    int top = pq.top();
                    pq.pop();
                    startFuel += top;
                    stops++;
                }
            }
            
            pq.push(stations[i][1]);
        }
        while(curr + startFuel < target)
        {   
            
            if(pq.empty())return -1;
            else 
            {
                int top = pq.top();
                pq.pop();
                startFuel += top;
                cout << curr + startFuel << endl;        
                stops++;
            }
        }
        
        return stops;
    }
};