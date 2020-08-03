class Solution {
public:
    bool search(vector<int>& arr, int target) {
        
        int L = 0;
        int R = arr.size() - 1;
        
        // Focus on deciding which search space to discard
        
        while(L <= R)
        {
            while(L + 1 < arr.size() && arr[L] == arr[L + 1])L++;
            while(R - 1 >= 0 && arr[R] == arr[R-1])R--;
            
            int mid = (R - L)/2 + L;
            
            
            if( arr[mid] == target)
                return true;
            if( arr[L] <= arr[mid])
            {
                if(target >= arr[L] && target < arr[mid])
                {
                    R = mid - 1 ;
                }
                else
                {
                    L = mid + 1;
                }
            }
            else if(arr[mid] <= arr[R])
            {
                if(target > arr[mid] && target <= arr[R])
                {
                    L = mid + 1;
                }
                else
                {
                    R = mid - 1;
                }
            }

        }
        return false;
    }
};
