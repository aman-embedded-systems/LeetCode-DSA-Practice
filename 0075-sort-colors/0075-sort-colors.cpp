class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int countRed=0;
        int Countwhite=0;
       // int countblue=0;
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            if(nums[left]==0)
            {
                countRed++;
            }
            else if(nums[left]==1)
            {
                Countwhite++;
            }
            left++;
        }
       // countblue=n-(countRed+Countwhite);

        for(int idx=0;idx<countRed;idx++)
        {
            nums[idx]=0;  //Red
        }
        for(int idx=countRed;idx<countRed+Countwhite;idx++)
        {
            nums[idx]=1;  //white
        }
        for(int idx=countRed+Countwhite;idx<n;idx++)
        {
            nums[idx]=2;  //blue
        }
        
    }
};