class Solution {
public:
    bool isPowerOfThree(int n) {
        // Based on the limitation of the int
        // so, if 3^19 is divisible by some lesser power.
         int num = pow(3, 19);
         
         return n > 0 && num % n == 0 ;
        
    }
};