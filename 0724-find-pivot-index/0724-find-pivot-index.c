int pivotIndex(int* nums, int numsSize) {
    int totalsum=0;
    for(int idx=0;idx<numsSize;idx++)
    {
      totalsum+=nums[idx];  
    }
    int leftsum=0;
    for(int idx=0;idx<numsSize;idx++)
    {
        if(leftsum==totalsum-leftsum-nums[idx])
        {
            return idx;
        }
       leftsum+=nums[idx];
    }
    return -1;
}