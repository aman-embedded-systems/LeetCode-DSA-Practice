class Solution {
    public:
    int digitProduct(int x) {
    int p = 1;
    while (x > 0) {
    p *= x % 10;
    x /= 10;
    }
    return p;
    }
    int smallestNumber(int n, int t) {
    for (int num = n; ; num++) {
    if (digitProduct(num) % t == 0) return num;
    }
    return -1;
    }

};