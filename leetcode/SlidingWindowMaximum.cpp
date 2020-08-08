/*
Maintain an invariant that the first element in the 
front of the deque or DLL is the largest element.

We don't keep invalid elements. We do this by storing indices
and checking whether they are still in the window. If not, then
we remove them. We do this by checking from the front since we 
insert the indices into the result array from the front.

To maintain the invariant of having dq.front() as the largest element,
we insert by comparing with the dq.back(). If nums[i] i.e the current 
element is larger than dq.back(), we pop the last element since this 
element can't be the largest in the window for current window as well
as future windows since i) we are inserting a larger value
                        ii) the larger value has a higher index
Having a higher index means that our newly inserted value is going 
to stay a longer. Subsequent window can have it as the max value.

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        int i;
        vector<int> maxinds;
        for(i = 0; i < k; i++)
        {
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        maxinds.push_back(dq.front());
        
        // Store index to figure out whether something is in window or not
        
        
        while( i < nums.size())
        {   
            while( !dq.empty() &&  dq.front() <= i - k  )
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            maxinds.push_back(dq.front());
            
            i++;
        }
        vector<int> maxints;
        for(int i : maxinds)
        {
            maxints.push_back(nums[i]);
        }
        return maxints;
    
    }
};
