class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        for(int i = nums.size() - 2; i >= 0; i--) // Put the elements from reverse because Last in First out. So the greater elements that are 
          // nearer should come first.
        {
            s.push(nums[i]);
        }
        vector<int> res;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            while(!s.empty() && s.top() <= nums[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                res.push_back(s.top());
                
            }else res.push_back(-1);
            s.push(nums[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
