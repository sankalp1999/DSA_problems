bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}

// 4^n - 1 = (2^n - 1) * (2^n + 1). Out of every three numbers 2^n - 1, 2^n, 2^n + 1,
// one has to be divisible by 3. 2^n cannot be so the other two can be and hence 4^n - 1
