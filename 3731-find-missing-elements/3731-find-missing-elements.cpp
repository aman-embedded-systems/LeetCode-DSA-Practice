class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // Step 1: Find the minimum and maximum elements in the array
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        // Step 2: Store elements in a hash set for O(1) lookups
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        
        std::vector<int> missing;
        
        // Step 3: Iterate through the range [min_val, max_val]
        for (int i = min_val; i <= max_val; ++i) {
            // If the current number is not in the set, it's missing
            if (num_set.find(i) == num_set.end()) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};