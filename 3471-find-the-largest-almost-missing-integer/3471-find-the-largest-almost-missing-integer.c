int largestInteger(int* nums, int numsSize, int k) {
    int subCount[51] = {0}; // subCount[v] tracks how many subarrays of size k contain value v

    for (int i = 0; i <= numsSize - k; i++) {
        int seenInSubarray[51] = {0};
        for (int j = i; j < i + k; j++) {
            if (!seenInSubarray[nums[j]]) {
                seenInSubarray[nums[j]] = 1;
                subCount[nums[j]]++;
            }
        }
    }

    // Find the largest value that appeared in exactly 1 subarray
    int ans = -1;
    for (int v = 50; v >= 0; v--) {
        if (subCount[v] == 1) {
            ans = v;
            break;
        }
    }

    return ans;
}