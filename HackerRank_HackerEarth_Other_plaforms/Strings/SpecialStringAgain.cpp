/*
Solution inspired by discussion comment
Question : find the no. of palindromic substrings with the propery that either all letters are same or only middle letter is different.

Explanation
asasd
I initially checked all the substrings by expanding on both the sides but it timed out.
This approach is unique in the way --> starting from i, i + 1 can either be same or different.

a s a count++;
a s a s break;

Now we check for s
s a s count++

So, if next character for startChar is same, then we continue checking for same char and increment at 
each step.

Now, if next char is different, we need to store it's index and make sure that subsequent s[j] 
is equal to startChar. We can check distance from j to mid and mid to i for that condition.

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {

    int count = s.size();

    for(int i = 0; i < n; i++)
    {
        char startchar = s[i];
        int diff_exist = -1;
        for(int j = i + 1; j < n; j++)
        {
            char currchar = s[j];
            if(currchar == startchar)
            {
                if(diff_exist == -1 || (j - diff_exist == diff_exist - i))
                {
                    count++;
                }
            }
            else 
            {
                if(diff_exist == -1)
                diff_exist = j;
                else
                break;
            }
        }
    }
    return count;
}
