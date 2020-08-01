/*
We use the same string again. Just ensure that i != j since we don't want to repeat the same string.
That way, the indices will cross while forming the subsequences. So, we add that condition in normal LCS code.
*/

#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size(), m= text2.size(); 
        vector<vector<int>> lookup(n+1, vector<int>(m+1, 0));
        int max1 = 0;
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(text1[i-1] == text2[j-1] && i != j)
                {
                    lookup[i][j] = 1 + lookup[i-1][j-1];
                }
                else
                    lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]); // new substring starting so length becomes zero.
            }
        }
        return lookup[n][m];
    }
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, m;
	    cin >> n ;
	    string text1, text2;
	    cin >> text1;
	    text2 = text1;
	    
	    cout << longestCommonSubsequence(text1, text2) << endl;
	    
	}
	return 0;
}
