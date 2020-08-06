/*
This solution takes the first bit and ors to end of the result number.
Then we right shift and repeat.
*/


unsigned int Solution::reverse(unsigned int A) {
    
    int a = 0;
    for(int i = 0; i < 32; i++)
    {
        int lsb = 0;
        lsb = A & (1 << 0);
        a = a | (lsb << 31 - i);
        A = A >> 1;
    }
    return a;
    
}
