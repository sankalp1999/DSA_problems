/*
  A = "myinterviewtrainer",
  B = ["trainer", "my", "interview"]
  
  The below depiction might not happen necessarily in the same order.
  
  m 
  my FOUND. Stack holds the current state and we call further. In the current state, remaining length iterations i = 3 .. i = A.length() are remaining
  Pass interviewtrainer.
  i
  in
  int
  inte
  inter
  interv
  intervi
  intervie
  interview. FOUND. Pass trainer.
  t
  tr
  trai
  train
  traine
  trainer. Pass ""
  return true;
*/

unordered_map<string,bool> mapper;

bool dfs(string A, unordered_set<string>& s)
{
    if(A.size() == 0)
        return true;
    if(mapper.find(A) != mapper.end() )
    {
        return mapper[A];
    }
    
    for(int i = 1; i <= A.length(); i++)
    {
        if( s.find(A.substr(0,i)) != s.end() && dfs(A.substr(i), s)) // Unlike backtracking, we just need to reach the end once. So, 
                                                                     // if we find a word in dict, move forward with rest of string. 
                                                                     // Notice the implementation of this problem, how wer use the 
                                                                     // substr. We are passing substrings 
        {
            return mapper[A.substr(i)] = true;
        }
    }
    return mapper[A] = false;
}

int Solution::wordBreak(string A, vector<string> &B) {
    mapper.clear();    
    unordered_set<string> s;
    for(string temp : B) // Fast lookup for the substring
    {
        s.insert(temp);
    }
    return dfs(A,s);
}
