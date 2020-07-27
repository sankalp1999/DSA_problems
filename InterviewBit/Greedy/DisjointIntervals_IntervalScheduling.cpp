/*
2nd solution is the editorial solution.
This is a non-trivial greedy problem.
You select the first interval with the earliest end/finish time. 
Then, we ignore the incompatible 

For proof, check out https://www.youtube.com/watch?v=2P-yW7LQr08&t=32s and BackToBack SWE video

We will solve this using greedy approach.

-> Sort the intervals, with respect to their end points.
-> Now, traverse through all the intervals, if we get two overlapping intervals, then greedily choose the interval with lower end point since, choosing it will ensure that intervals further can be accommodated without any overlap.
-> Apply the same procedure for all the intervals and return the count of intervals which satisfy the above criteria.

*/

bool compare(pair<int,int>& a, pair<int,int>& b)
{
    return a.second < b.second;
}

int Solution::solve(vector<vector<int> > &A) {
    
    vector<pair<int,int>> v;
    for(int i = 0; i < A.size(); i++)
    {
        v.push_back({A[i][0], A[i][1]});
    }
    sort( v.begin(), v.end(), compare); // Sort according to end times

    int start  = v[0].first;
    int count = 1;
    int end = v[0].second;
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i].first <= end) // If end time >= start, that means an overlap
        {
            continue; // incompatible
        }
        end = v[i].second;
        count++;
    }
    return count;
    
}


bool sortbysec(vector<int> &a, vector<int> &  b)
{
    return (a[1] < b[1]);
}


/* Editorial Solution */

// Function to find maximal disjoint set
int Solution::solve(vector<vector<int> > &A) {
      // Sort the list of intervals
      sort(A.begin(), A.end(), sortbysec);

      int ans = 1;

      // End point of first interval
      int r1 = A[0][1];

      for (int i = 1; i < A.size(); i++) {
          int l1 = A[i][0];
          int r2 = A[i][1];

          // Check if given interval overlap with previously included interval, if not
          // then include this interval and update the end point of last added interval
          if (l1 > r1) {
              ans += 1;
              r1 = r2;
          }
      }
      return ans;
}
