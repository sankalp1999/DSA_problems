/*
This problem can be probably done without 2d array but
it's a slight variation in LCS code.
We just start from scratch again
whenever we come across different character.
*/


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
                    max1 = max(max1, lookup[i][j]); // New substring can happen anywhere
                }
                else
                    lookup[i][j] = 0; // new substring starting so length becomes zero.
            }
        }
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
