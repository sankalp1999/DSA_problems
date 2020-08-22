#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

    int count1[26] = {0};
    int count2[26] = {0};
    for(char c : a)
    {
        count1[c - 'a']++;
    }
    for(char c : b)
    {
        count2[c - 'a']++;
    }
    int sum = 0;
    for(int i = 0; i < 26; i++)
    {
        while(count1[i] > count2[i])
        {
            count1[i]--;
            sum++;
        }
        while(count2[i] > count1[i])
        {
            count2[i]--;
            sum++;
        }
    }
    return sum;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
