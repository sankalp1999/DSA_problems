class Solution {
public:
    
    int eval(vector<int>& piles, int mid)
    {
        int hours_required = 0;
        
        for(int i = 0; i < piles.size(); i++)
        {
            hours_required = hours_required +   (piles[i] + mid - 1) / mid;
        }
    
        return hours_required;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        long long int high = *max_element(piles.begin(), piles.end());
        // Learning: Will have to think a bit about the bounds of the binary search
        
        int low = 1; // If you have speed of 0, then you can never complete eating so 1.
        
        int min_K = high;
        
        while(low <= high)
        {
            int mid = (high - low)/2 + low;
            int hours_required = eval(piles, mid);

            if( hours_required > H) 
            {
                low = mid + 1;
            }
            else if(hours_required <= H) // Depending on lower_bound or upper_bound, you can have two ifs
            {
                min_K = min(min_K, mid);
                high = mid - 1;
            }
        }

        return min_K;
    }
};
