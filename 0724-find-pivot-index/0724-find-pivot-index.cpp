class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int totalsum=0;

        int n=nums.size();

        for(int idx=0;idx<n;idx++)
        {
            totalsum=totalsum+nums[idx];
        }
        int leftsum=0;
        for(int idx=0;idx<n;idx++)
        {
            if(leftsum==totalsum-leftsum-nums[idx])
            {
                return idx;
            }
            leftsum+=nums[idx];
        }
        return -1;
    }
};