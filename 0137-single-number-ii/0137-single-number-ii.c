int singleNumber(int* nums, int numsSize) {
    int n=numsSize;
   
    int result=0;

    for(int idx=0;idx<32;idx++)
    {
         int count=0;
         for(int idy=0;idy<n;idy++)
         {
            count+=(nums[idy]>>idx)&1;
           
         }
        if(count%3)
        {
            result|=(1u<<idx);
        }
    }
    return result;

}