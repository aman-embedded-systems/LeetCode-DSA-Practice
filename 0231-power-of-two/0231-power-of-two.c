bool isPowerOfTwo(int n) {
    // if(INT_MIN < n < INT_MAX)
    // {
    //     return true;
    // }
    if((n > 0 && (n & (n-1))==0))
    {
        return true;
    }
    return false;
}