int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //  We do a binary search on the lower size array
        // We select k1 + k2 = k elements from both the arrays
        // If l1 <= r2 and l2 <= r1, then we have a chance at a 
        // correct answer
        
        if(n > m)
        {
            return kthElement(arr2,arr1,m,n,k);
        }
        
        // we maintain n to be smallelr
        
        int low = max(0,k-m);// if k is greater than m(size of arr2), 
        // so we need to select atleast a few elements from m
        int high = min(k,n); // If k is smaller than size of 
                            // first array, then take min since we are only going to select k elements.
  
        // arr1 = {1,2,3,4}
        // Then at max we can take 4 elements from array1. At minimum, we can take 0 elements
        // low and high are the partition points.
        // cut1-1 is left side and cut1 is the right side
  
        int l1, l2, r1, r2;
        while(low <= high)
        {
            int cut1 = (high - low)/2 + low;
            int cut2 = k - cut1;  // We take k elements only in total.
            
            l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            r1 = cut1 == n ? INT_MAX : arr1[cut1];
            r2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            if(l1 <= r2 and l2 <= r1)
            {
                return max(l1,l2);
            }
            else if(l1 > r2)
            {
                // we need to go back
                // to reduce the value of l1
                // subsequently more elements
                // are added in the l2
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
            
        }
        return 1;
    }
