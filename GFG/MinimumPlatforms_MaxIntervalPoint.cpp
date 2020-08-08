#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<string,char>> maxinterval;
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            maxinterval.push_back({s,'A'});
        }
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            maxinterval.push_back({s,'B'});
        }
        
        sort(maxinterval.begin(), maxinterval.end());
        int count = 0;
        int max_count = 0;
        for(int i = 0; i < maxinterval.size(); i++)
        {
            max_count = max(max_count, count);
            if(maxinterval[i].second == 'A')count++;
            else count--;
            
        }
        cout << max_count << endl;
        
        
    }
	return 0;
}
