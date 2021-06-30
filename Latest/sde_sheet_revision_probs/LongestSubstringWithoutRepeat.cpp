
// O(N) solution
// Here, we store the last seen index of the character.
// Next time if we come across it i.e it is going to repeat, we jump our left to 
// an index which is 1 + last seen. So, we don't have to drag the left pointer
// all the way. 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> maap;
        for(char c : s)
        {
            maap[c]=-1;
        }
        int left = 0;
        int right = 0;
        int max_ = 0;
        while(right < s.size())
        {
            if(maap[s[ right] ] >= 0 )
            left = max(left, maap[s[right]] + 1); // Remove duplicate, so jump in front of the last seen 
            maap[s[right]] = right;
            right++;
            max_ = max(max_, right - left );
        }
        return max_;
    }
};


// O( 2 * N) ~ O(N) solution. Here, the left pointer drags till the repeating character inside
// the current window is not found.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> set1;
        int left = 0;
        int right = 0;
        int max_ = 0;
        while(right < s.size())
        {
            while(set1[s[right]] < 1 and right < s.size()) // Try to make the longest window without having a repeated character
            {
                set1[s[right]]++;
                right++;
            } 
             max_ = max(max_, right - left);
          // If found a repeated character, then we come here. We remove one and try again after left++
            set1[s[left]]--;
            left++;
        }
        return max_;
    }
};
