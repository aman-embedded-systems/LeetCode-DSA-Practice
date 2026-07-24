int mySqrt(int x) {
     if (x == 0 || x == 1) return x;

        int left = 1, right = x;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Use division (mid <= x / mid) to avoid integer overflow 
            // instead of (mid * mid <= x)
            if (mid <= x / mid) {
                ans = mid;     // mid could be our answer, try finding a larger one
                left = mid + 1;
            } else {
                right = mid - 1; // mid is too large, search in the left half
            }
        }

        return ans;
}