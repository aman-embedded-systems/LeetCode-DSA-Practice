class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // Stores: {number, index}
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement already exists in the map
            if (num_map.count(complement)) {
                return {num_map[complement], i};
            }
            
            // Otherwise, add the current number and its index to the map
            num_map[nums[i]] = i;
        }
        
        return {}; // Return empty if no solution is found (though constraints guarantee one)
    }
};