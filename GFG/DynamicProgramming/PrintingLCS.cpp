#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size(), m= text2.size(); 
        vector<vector<int>> lookup(n+1, vector<int>(m+1, 0));
        int max1 = 0;
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(text1[i-1] == text2[j-1])
                {
                    lookup[i][j] = 1 + lookup[i-1][j-1];
                    // max1 = max(max1, lookup[i][j]);
                }
                else
                    lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
            }
        }
          // one by one store characters in lcs[] 
   int i = n, j = m; 
   string s = "";
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (text1[i-1] == text2[j-1]) 
      { 
          s.push_back(text1[i-1]); // Put current character in result 
          i--; j--; // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (lookup[i-1][j] > lookup[i][j-1]) 
         i--; 
      else
         j--; 
   } 
    reverse(s.begin(), s.end());
   // Print the lcs 
   cout << s << endl; 
    return max1;
    }
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, m;
	    cin >> n >> m;
	    string text1, text2; 
	    cin >> text1 >> text2 ;
	    cout << longestCommonSubsequence(text1, text2) << endl;
	    
	}
	return 0;
}
