/*
This is a simple solution in which we just expand from each character and check for palindrome
in both sides since "Substring" has to be found. The function is similar. 

With the same expand function, this can be easily achieved. No need to use of DP. Use DP for longest Palindromic subsequence
where you find LCS between palindrome and the original word. That is the answer in that.

Time complexity : O( N ^ 2)
*/


class Solution {
public:

    
    int expand(int i, int j, string& s)
    {
        int count = 0;
        if(i == j)count = -1; // Because we are doing count += 2 for even case but for odd, we start with count = 1
        int p = 0;
        while(i-p>=0 && j + p < s.size())
          {
              if(s[i-p] == s[j + p])
              {
                  p++;
                  count+=2;
              }
              else
                  break;
          }
        return count;
      }
    
    string longestPalindrome(string s) {
        
        int res = 0;
        int pos;
        
        if(s.size() <= 1)return s;
        
        for(int i = 0; i < s.size() - 1; i++)
        {
            // one even case
            // one odd case
            int odd = expand(i, i, s);
            int even = expand(i, i + 1, s);
            int bigger = max(odd, even);
            
            if(bigger > res)
            {
                res = bigger;
                if(even > odd)
                pos = i - bigger/2 + 1; // Some simple observations.
                else
                    pos = i - bigger/2; 
            }
            
        }

        return s.substr(pos, res);
    }
};
