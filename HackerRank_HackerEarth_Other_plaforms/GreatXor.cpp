#include <bits/stdc++.h>

using namespace std;

// Complete the theGreatXor function below.

// Go from left to right. If u get a 1 after msb
// then, i can flip it to 1. Now, this number is 
// is bigger than x. We can flip all the bits (2 * pos - 1) choices are there since
// we have 1 at xth position, all the resulting numbers by flipping bits on 
// right side will still result in a bigger number.

// So, we just iterate from right to left or left to right and add
// 2 ^ (i - 1) for each zero we encounter.


long theGreatXor(long x) {
    long long int sum = 0;
    int num_bits = log2(x) ;
    for(int i = 0; i < num_bits; i++)
    {
        if( (x & (1L << i) ) == 0 )
        {
            sum = sum +  (1L << i);   
        }
    }
    return sum;

}
