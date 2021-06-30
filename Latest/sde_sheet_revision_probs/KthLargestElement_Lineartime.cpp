class Solution {
public:
    
    // Lomuto partition
    int partition(vector<int>& nums, int l, int r) 
    {
        int p = random() % (r - l + 1);
        swap(nums[r], nums[r - p]);
        int pivot = r;
        for(int i = l ; i < r; i++)
        {
            if(nums[i] <= nums[pivot])
            {
                swap(nums[l++], nums[i]);
            }
        }
        swap(nums[pivot], nums[l]);
        return l;
    }
//     int HoarePartition(vector<int>& nums, int l, int r)
//     {
//         int pivot = l;
//         int i = l;
//         int j = r;
//         while(1)
//         {
//             while(i < r and nums[i] <= nums[pivot] )i++;
//             while(j > l and nums[j] > nums[pivot] )j--;
//             if(i < j)swap(nums[i], nums[j]);
//         }
//         swap(j,pivot);
//         return j;
//     }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        k = nums.size() - k ;
        // The pivot is going to be in its sorted position
        // This means pos < k, then we need to go further right.
        int pos;
        while(left <= right)
        {
            // pos = partition(nums, left, right);
            pos = partition(nums,left,right);
            if(pos == k)
            {
                return nums[pos];
            }
            else if(pos < k) // The pivot 
            {
                left = pos + 1;
            }
            else 
                right = pos - 1;
        }
        return pos;
    }
};
