int maximumProduct(int* nums, int numsSize) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        int d = nums[i];

        // Update top 3 maximums
        if (d > max1) {
            max3 = max2;
            max2 = max1;
            max1 = d;
        } else if (d > max2) {
            max3 = max2;
            max2 = d;
        } else if (d > max3) {
            max3 = d;
        }

        // Update top 2 minimums
        if (d < min1) {
            min2 = min1;
            min1 = d;
        } else if (d < min2) {
            min2 = d;
        }
    }

    // Product of 3 largest vs Product of 2 smallest and 1 largest
    long long prod1 = (long long)max1 * max2 * max3;
    long long prod2 = (long long)min1 * min2 * max1;

    return (prod1 > prod2) ? prod1 : prod2;
}