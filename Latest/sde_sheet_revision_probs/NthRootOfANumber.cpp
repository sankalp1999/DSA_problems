int NthRoot(int n, int m)
	{
	    // Code here.
	    double low = 0;
	    double high = m ;
	    double val;
	    double mid;
	    while(high - low > 1e-9){
	        mid = (low + high)/2.0;
	        val = pow(mid, n);
	       
	         if(val < m)
	         {
	             low = mid ;
	         }
	         else
	         high = mid ;
	    }
	    if(high - (int)high < 1e-9)return high;
	    else return -1;
	}  
