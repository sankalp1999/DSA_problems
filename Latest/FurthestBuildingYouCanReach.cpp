class Solution {
public:
    // Binary search based solution
    int solve(int mid, vector<int>& heights, int bricks, int ladders)
    {
       priority_queue<pair<int,int>> maxHeap; 
       for(int i = 1; i <= mid; i++)
       {
           maxHeap.push({heights[i]-heights[i-1], i-1});
       }
        unordered_map<int,int> mapper;
        int k = ladders;
        while(!maxHeap.empty() and ladders--)
        {
            auto top = maxHeap.top();
            maxHeap.pop();
            mapper[top.second] = top.first;
        }
        int n = heights.size();
        int maxP = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(heights[i] < heights[i+1])
            {
                if(mapper.find(i) != mapper.end() and k > 0)
                {
                    maxP = i + 1;
                    k--;
                    continue;
                }
                else if(bricks >= heights[i + 1] - heights[i])
                {
                    bricks -= heights[i + 1] - heights[i];
                    maxP = i + 1;
                }
                else break;
            }
            else
            {
                maxP = i + 1;
            }
        }
        return maxP;
    }
    
    // Binary search on the lat index
    // for ladders, each time we build function,
    // we make sure that we use ladder for largest difference
    // This futher gives the logic that we might 
    // just keep using bricks and if we encounter 
    // a bricks < diff, then we might use a ladder
    // for the largest bricks a few time ago. 
    // We will use ladder at that place and those bricks
    // can be used now (and we might use a ladder at this place
    // also. That is the heap solution.
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int low = 0;
        int high = heights.size() - 1;
        int maxP = 0;
        // mid might be the last index we can reach
        while(low <= high)
        {
            int mid = (high - low)/2 + low;
            int pos = solve(mid, heights, bricks, ladders);
            maxP = max(pos, maxP);
            if(pos >= mid)
                low = mid + 1;
            else if(pos < mid)
            {
                high = mid - 1;
            }
        
        }

        return maxP;
    }
    
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // MaxHeap based solution
        // We try to use the bricks
        // and store them in a maxheap
        // When we run out of bricks, we 
        // add them from pq.top() if we have ladders > 0
        priority_queue<int> maxHeap;
        int n = heights.size();
        int i = 0;
        for( i = 1; i < n; i++)
        {
            int diff = heights[i] - heights[i-1];
            if(heights[i-1] < heights[i])
            {
                if(bricks - diff >= 0)
                {
                    bricks -= diff;
                    maxHeap.push(diff);
                }
                else if(bricks < diff and ladders > 0)
                {   
                    // In this case, we replace 
                    // previou larger brick wall by a ladder
                    if(maxHeap.size()>0)
                    {
                         int x = maxHeap.top();
                        if(x >= diff)
                        {
                            bricks += x;
                            maxHeap.pop();
                            maxHeap.push(diff);
                            bricks -= diff;
                        }
                    }
                    // Otherwise, just use ladder
                    // no other option Both the 
                    // cases, we end up 
                    // using one ladder
                    ladders--;
                 
                }
                else break;
           
            }
            
        }
        return i-1;
    }
};


