// Solution by chuchao333 @leetcode better than mine.

class Solution {
public:
    int findMin(vector<int>& arr) {
        // Is there something special about the minimum element?
        // Yes, we can observe a dip in the array. It is really easy to fidn the minimum element
        // in linear time.
        
        // Can I do better? Ofcourse, Binary search.
        
        // Maybe, i will do just a search on a rotated array. Then, continue the search till
        // I get that dip point by comparing the arr[mid] > arr[mid-1]
        
        int L = 0;
        int R = arr.size() - 1;
        int mid;
        while(L <= R)
        {
            mid = (L + R)/2;
            
            if(mid - 1 >= 0 && arr[mid] < arr[mid-1])return arr[mid];
            
            if(arr[mid] > arr[R]) // This means we are not in a sorted segment, so go to one.
            {
                L = mid + 1;
            }
            else
            {
                if(mid - 1 >= 0 && arr[mid] > arr[mid-1]) // We are in a sorted segment since arr[mid] <= arr[R], so answer should be on left part.
                {
                    R = mid - 1;
                }
                else
                    return arr[mid];
            }
        }
        return -1;
      
    }
};


//Solution by changhaz @Leetcode

//Looking at subarray with index [start,end]. We can find out that if the first member is less than the last member, there's no rotation in the array. So we could directly return the first element in this subarray.

//If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element. If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. Else, it is in the first half in the array.



 int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;
        
        while (start<end) {
            if (num[start]<num[end])
                return num[start];
            
            int mid = (start+end)/2;
            
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return num[start];
    }
