class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int first, last;
        first = INT_MAX;
        last = -1;
        while(low <= high)
        {
            int mid = (high - low)/2 + low;
            if(nums[mid] == target)
            {
                first = min(first,mid);
                high = mid - 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if(first == INT_MAX)first = -1;
        low = 0;
        high = nums.size() - 1;
        while(low <= high)
        {
            int mid = (high - low)/2 + low;
            if(nums[mid] == target)
            {
                last = max(last,mid);
                low = mid + 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        vector<int> res;
        res.push_back(first);
        res.push_back(last);
        return res;
    }
};
