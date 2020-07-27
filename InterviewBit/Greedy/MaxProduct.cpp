
int Solution::maxp3(vector<int> &A) {
   
   sort(A.begin(), A.begin());
   int n = A.size() - 1;
   long long int pos = A[n]*A[n-1]*A[n-2];

   // If all negative, this will give proper answer                                                
   long long int neg = A[0]*A[1]*A[n];
   cout << pos << " negative : " << neg << endl;
   return max(neg, pos);
       
}
