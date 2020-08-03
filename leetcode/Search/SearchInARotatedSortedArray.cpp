/*
The main idea is to check whether we are in a sorted region or not. Then, if we are in a 
sorted segment, we have to decide to continue in this region or not.
*/


class Solution {
public:
    int search(vector<int>& arr, int target) {
        int L = 0;
        int R = arr.size() - 1;
        while( L <= R)
        {
            int mid = (L + R)/2;
            if(arr[mid] == target)
            {
                return mid;
            }
            else if(arr[mid] >= arr[L] ) // Only the part from L to mid is sorted.
            {
                
                // We check the area between left bound and mid bound. Whether target element
                // lies in this area or not.
                if(target >= arr[L] && target <= arr[mid])
                {
                    R = mid - 1; // If so, we search in this segment only
                }
                else // We better find a sorted array in the right part of the array.
                    L = mid + 1;       
            }
            else if(arr[mid] <= arr[R])
            {
                if(target >= arr[mid] && target <= arr[R])
                {
                    L = mid + 1;
                }
                else
                    R = mid - 1;       
            }
        }
        return -1;
    }
};
