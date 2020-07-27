/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compare(Interval& a, Interval &b)
 {
     return a.start < b.start;
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> res;
    sort(A.begin(), A.end(),[](Interval a, Interval b){return a.start < b.start;});
    int start = A[0].start;
    int end = A[0].end;

    for(int i = 1; i < A.size(); i++)
    {
        if(end < A[i].start)
        {
            Interval s;
            s.start = start;
            s.end = end;
            res.push_back(s);
            start = A[i].start;
            end = A[i].end;
        }
        /*
        else if(start == A[i].start && A[i].end <= end)continue;
        else if(start == A[i].start && A[i].end > end)
        {
            end = A[i].end;
        }
        */
        else
        {
        end = max(end, A[i].end);
        }
    }
    Interval s;
    s.start =start;
    s.end = end;
    res.push_back(s);
    return res;
}
