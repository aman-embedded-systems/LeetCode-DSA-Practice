class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& visited, vector<vector<int>>& ans) {
        // Base case: if the current permutation length equals nums length
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip if the element is already used in the current path
            if (visited[i]) continue;
            
            // Choose the element
            visited[i] = true;
            current.push_back(nums[i]);
            
            // Recurse
            backtrack(nums, current, visited, ans);
            
            // Backtrack: undo the choice
            current.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
     vector<vector<int>> ans;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        
        backtrack(nums, current, visited, ans);
        return ans;
    }
};