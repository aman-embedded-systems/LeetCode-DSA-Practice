class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>majrity;
        int count1=0;
        int n=nums.size();
        int prevDigitDump=INT_MIN;
        if(n==1)
        {
             majrity.push_back(nums[0]);
             return majrity;
        }
        else if(n==2)
        {
            if(nums[0]==nums[1])
            {
                majrity.push_back(nums[0]);
                return majrity;
            }
            else
            {
              majrity.push_back(nums[0]);
              majrity.push_back(nums[1]);
              return majrity;
            }
            
            
        }
        sort(nums.begin(),nums.end());
        for(int idx=0;idx<n-1;idx++)
        {
            if(nums[idx]==nums[idx+1])
            {
                count1++;
                if(count1>=n/3 && nums[idx]!=prevDigitDump)
                {
                    prevDigitDump=nums[idx];
                    majrity.push_back(nums[idx]);
                }
            }
            else
            {
                count1=0;
            }
        }
        return majrity;
    }
};