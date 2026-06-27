class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> quad;
        int n = nums.size();
        if (n < 4) return quad;

        // 1. Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());

        // 2. First pointer loop
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 3. Second pointer loop
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate values for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 4. Two-pointer approach for the remaining two elements
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to prevent integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        quad.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third element
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for the fourth element
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        // Move both pointers inward
                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++; // We need a larger sum
                    } 
                    else {
                        right--; // We need a smaller sum
                    }
                }
            }
        }
        return quad;
    }
};