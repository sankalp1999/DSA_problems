
/* 1st attempt 
The main idea is that if check for both 1 greater and 1 lesser element,
then we are double contributing. ( I was doing this earlier)

Golden points
We only attempt to build sequences from numbers that are not already part of a longer sequence.
This is accomplished by first ensuring that the number that would immediately precede the current number in a 
sequence is not present, as that number would necessarily be part of a longer sequence.

1. First, we remove all the duplicates from the array. We do this using the unordered_set.
2. Now, as we traverse, [100,200,1,3,2,4] suppose, we come across 1, then we search for 2, if we find 2, then we search for 3 and then we 
   search for 4. Search is O(1) since we are using unordered_set.
3. Another detail is that while traversing if there is a smaller element, then we skip that and continue because
   we will have it in our streak or sequence later on when we search from a smaller element.
4. If still not understood, check this awesome video     // https://www.youtube.com/watch?v=xdMyL--dOqE
*/


/* 2nd attempt */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        int count;
        int max_count = 1;
        unordered_set<int> s;
        for(int i : nums)s.insert(i);
        nums.resize(s.size());
        for(auto it : s)
            nums.push_back(it);
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            count = 1;
            if(s.find(num-1)!=s.end())continue;
            while(s.find(num+1) != s.end())
            {
                count++;
                num = num + 1;
                max_count = max(max_count, count);
            }
        }
        return max_count;
    }
};
