/*
You are given a string containing characters  and  only. Your task is to change it into a string such that there are no matching adjacent characters. 
To do this, you are allowed to delete zero or more characters in the string.
*/

int alternatingCharacters(string s) {
    int count = 0;

    for(int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            count++;
        }
    }
    return count;

}
