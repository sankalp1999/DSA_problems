class Solution {
public:
    vector<int> temp;
    vector<int> original;
    Solution(vector<int>& nums) {
        int n = nums.size();
        temp.resize(n);
        original.resize(n);
        for(int i = 0; i < n; i++)
        {
            temp[i] = nums[i];
            original[i] = nums[i];
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        temp = original;
        return temp;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        int last_index = (int)temp.size();
        int n = temp.size();
        for(int i = 0; i < n; i++)
        {
            int randomidx = rand() % last_index;
            last_index--;
            swap(temp[randomidx],temp[last_index]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
