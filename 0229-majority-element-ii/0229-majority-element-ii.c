/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    
    int *majrityElement=(int*)malloc(2*sizeof(int));
    int Candidate1=0;
    int Candidate2=0;
    int Count=0;
    int Count2=0;
    int MajrityElementThreshold=numsSize/3;
    for(int idx=0;idx<numsSize;idx++)
    {
        if(nums[idx]==Candidate1)
        {
            Count++;
        }
        else if(nums[idx]==Candidate2)
        {
            Count2++;
        }
        else if(Count==0)
        {
            Candidate1=nums[idx];
            Count=1;
        }
        else if(Count2==0)
        {
            Candidate2=nums[idx];
            Count2=1;
        }
        else
        {
            Count--;
            Count2--;
        }
    }
    Count=0;
    Count2=0;
    int countsize=0;
    for(int idx=0;idx<numsSize;idx++)
    {
        if(nums[idx]==Candidate1)
        {
            Count++;
        }
        else if(nums[idx]==Candidate2)
        {
            Count2++;
        }
    }
    if(Count>MajrityElementThreshold)
    {
        majrityElement[countsize++]=Candidate1;
        
    }
    if(Count2>MajrityElementThreshold)
    {
         majrityElement[countsize++]=Candidate2;
    }
   *returnSize = countsize;
   return majrityElement;
    
}