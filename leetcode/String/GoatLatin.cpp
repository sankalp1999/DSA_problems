/*
Implementation problem.
*/
class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> s;
        string temp = "";
        for(char c : S)
        {
            if(c == ' ')
            {
                s.push_back(temp);
                temp = "";
            }
            else
            {
                temp += c;
            }
        }
        s.push_back(temp);
        for(int i = 0; i < s.size(); i++)
        {
            string temp = s[i];
            if(temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u' || temp[0] == 'A' || temp[0] == 'E' || temp[0] == 'I' || temp[0] == 'O' || temp[0] == 'U')
            {
               temp += "ma";
            }
            else
            {
                temp.push_back(temp[0]);
                temp += "ma";
                temp = temp.substr(1);
            }
            int k = i + 1;
            while(k--)temp.push_back('a');
            s[i] = temp;
        }
        string sentence = "";
        for(int i = 0; i < s.size(); i++)
        {
            sentence += s[i];
            sentence += " ";
        }
        sentence.pop_back();
        return sentence;
        
    }
};
