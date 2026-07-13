class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0;
        int twos=0;
        int n=nums.size();
        for(int idx=0;idx<n;idx++)
        {
            ones=ones^(nums[idx] & ~twos);
            twos=twos^(nums[idx] & ~ones);
        }
        return ones; 
    }
};