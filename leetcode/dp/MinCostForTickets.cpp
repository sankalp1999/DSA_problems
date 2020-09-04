/*
Completely solved on my own!!!!!!!!!!!!
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<int> dp(n + 1, 1e5);
        
        dp[0] = 0; // 0th day is going to be 0
        for(int i = 1; i <= days.size(); i++)
        {
            
            for(int j = 1; j < i; j++)
            {
                if(days[i-1] - days[j-1] < 7)
                {
                    dp[i] = min(dp[i], dp[j-1] + costs[1]); // Buy a 7 day pass from 8th past day
                }
                if(days[i-1] - days[j-1] < 30)
                {
                    dp[i] = min(dp[i], dp[j-1] + costs[2]); // Buy a 30 day pass from 31st day back
                }
            }
            dp[i] = min(dp[i], dp[i-1] + min({costs[0], costs[1], costs[2]})); // Single day case
        }
        return dp[n];
     
        // Another solution. This is linear time in space and time. O(365)
        
        unordered_set<int> find_days(begin(days), end(days));
        vector<int> dp(367, 1e5);
        dp[0] = 0;
        for(int i = 1; i <= 365; i++)
        {
            if(find_days.find(i) == find_days.end())
            {
                dp[i] = dp[i-1]; // If that day is not there, then just carry over.
            }
            else
            {   
                // add costs before that particular day and add new costs
                dp[i] = min({dp[i-1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0,i - 30)] + costs[2] });
            }
        }
        return dp[365];
        
    }
};
