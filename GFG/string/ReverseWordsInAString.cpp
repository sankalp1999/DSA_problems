#include <bits/stdc++.h>
using namespace std;


void rev(string &S, int left, int right)
{
    while(left < right)
    {
        swap(S[left], S[right]);
        left++;
        right--;
    }
}

// The front of the word and the back of the word is not having 
// .. So you have to consider that.

string reverseWords(string S) 
{ 
    
    reverse(S.begin(), S.end());
    
    int left, right;
    right = 0;
    left = 0;
    int flag = 0;
    
    for(right = 0; right < S.size(); right++)
    {
        if(S[right] == '.')
        {
            
            rev(S,left,right-1);
            left = right + 1;
        }
    }

    rev(S,left,right - 1);
    return S;
} 

