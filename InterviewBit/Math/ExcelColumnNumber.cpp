/*
Base 26 number conversion
*/


int Solution::titleToNumber(string A) {
    
    int i = A.size() - 1;
    int columnNumber = 0;
    int k = 0;
    for( ; i >= 0; i--)
    {
        columnNumber = columnNumber + ((A[i] - 'A') + 1) * pow(26, k++);
    }
    return columnNumber;
}
