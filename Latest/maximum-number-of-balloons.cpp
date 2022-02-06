// https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[26] = {0};
        for(char c : text)
        {
            arr[c - 'a']++;
        }
      
        // Answer is constrained by the number of l and o since we require 2 'l' and 'o' for each
        // balloon
      
        arr['l' - 'a'] = arr['l' - 'a']/2;
        arr['o' - 'a'] = arr['o' - 'a'] / 2;
        return min({arr['l'-'a'],arr['o'-'a'], arr[0],arr[1],arr['n'-'a']});
    }
};
