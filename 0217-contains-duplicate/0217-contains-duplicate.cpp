class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int idx=0;idx<n-1;idx++)
        {
            if(nums[idx]==nums[idx+1])
            {
                return true;
            }
        }
     return false ;
    }
};