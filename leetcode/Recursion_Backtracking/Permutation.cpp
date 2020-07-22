
/*
1 
1 2 
1 2 3 
1 3 
1 3 2 
2 
2 1 
2 1 3 
2 3 
2 3 1 
3 
3 1 
3 1 2 
3 2 
3 2 1 

The code goes from 
i = 0. curr = []. First dfs call happens. This will be on hold for a long time.  (1)
1 -> 1,2 -> 1,2,3 
Print 1 2 3 and return
Backtrack. 3 popped T T F. Get out of the for loop. Jump back to previous dfs call when i = 1. Curr is [1,2]
We continue from the pop_back() statement here. 
2 gets popped. T F F. Curr is [1] 
Notice, i was equal to 1 when we had called dfs. ** i goes to 2. ** The visited[2] = F. Hence 3 is pushed into current. [1,3] T F T
Make a dfs call from here. 
i = 0. visited[0] = T Hence for loop continues. i = 1 now. visited[1] = F. Add 2 [1,3,2]. Add to res vector. Backtrack.
[1,3] T F T i = 2
visited[2] = T
hence loop continues and we get out of for loop.
Backtrack to last dfs call.
3 gets popped. This call is completed.

We get out of the loop. 
Load back to the first dfs call where i = 0 (1)
Now, we go to next iteration and nums[1] = 2. Same process keeps going on.

*/


class Solution {
public:

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, vector<bool>& visited)
    {
    
        if(curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i])continue;
            curr.push_back(nums[i]);
            visited[i] = true; // Choose
            dfs(nums, res, curr, visited); // Explore
            curr.pop_back();
            visited[i] = false; // Unchoose
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> visited(nums.size());
        
        dfs(nums, res, curr, visited);
        return res;
    }
};
