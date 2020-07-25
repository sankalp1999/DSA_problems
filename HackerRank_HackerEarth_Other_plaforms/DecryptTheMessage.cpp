#include <bits/stdc++.h>
using namespace std;

/*
Find the words individually and keep moving.
Record the minimum level. 
That is the number of spaces.
*/

long long int min_num = 10000000;

void decrypt(unordered_set<string>& myset, string& s, int begin, long long int level, string prefix)
{
    if(begin >= s.size())
    {
        min_num = min(min_num, level - 1);
        // cout << level << endl;
       // cout << "CAme" << endl;
        return;
    }
    string temp = "";
    // cout << begin << endl;
    for(int i = begin; i < s.size(); i++)
    {
        temp += s[i];
       
        
        if(myset.find(temp) != myset.end())
        {
             string prev = prefix;
            prefix += temp;
            decrypt(myset, s, i + 1, level + 1, prefix );
            prefix = prev;
        }
       
    }
}


int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
        // Trie* root = new Trie();
        string s;
        cin >> s;
        int n;
        cin >> n;
        unordered_set<string> myset;
        while(n--)
        {
            string temp;
            cin >> temp;
            myset.insert(temp);
            // root->insert(temp);
        }

        int count = 0;
       long long int level = 0;
        string prefix = "";
      decrypt(myset , s, 0, level, prefix);
        
       if(min_num != 10000000 )
       {
            cout << min_num << endl;
       }
       else
        cout << "IMPOSSIBLE" << endl;
       min_num = 10000000;
       
    }
    
    return 0;     
}
   
