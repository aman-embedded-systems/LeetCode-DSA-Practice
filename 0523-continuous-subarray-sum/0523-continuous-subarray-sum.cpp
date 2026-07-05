class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        //map to store the first time we see
        unordered_map<int,int>remaindermap;

        remaindermap[0]=-1;
        int currentSum=0;
        for(int idx=0;idx<nums.size();idx++)
        {
            currentSum+=nums[idx];
            int remainder=currentSum%k;

            if(remaindermap.find(remainder)!=remaindermap.end())
            {
                if(idx-remaindermap[remainder]>=2)
                {
                    return true;
                }
               
            }
             else
                {
                    remaindermap[remainder]=idx;
                }
        }
        return false;
    }
};