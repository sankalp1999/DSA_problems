class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums.back() or nums.size() == 1)
            return nums[0];
        int low = 0;
        int high = n - 1;
        int res = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            res = min(nums[mid], res);
            if(nums[mid] > nums[high])  // this works because this means our inflection point should be in between
            { 
              
                 // or nums[mid] > nums[low]
                // We are in a sorted segment. Since rotation 
                // happens from right to left, 
                // elements before low should be lesser than it
                low = mid + 1;
            }
              else if(nums[mid] < nums[high]) // better search in left then
            {   
                high = mid - 1;
            }
          // else  FOR Duplicate case)
          // high--. Making a decision here is hard.
            
        }
        
    return res;
    }
};


