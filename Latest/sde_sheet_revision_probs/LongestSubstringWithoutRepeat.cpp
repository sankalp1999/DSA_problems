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
