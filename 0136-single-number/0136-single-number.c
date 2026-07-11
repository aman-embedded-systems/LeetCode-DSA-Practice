int singleNumber(int* nums, int numsSize) {
    int n=numsSize;
    int UniqueNumber=nums[0];
    for(int idx=1;idx<n;idx++)
    {
        UniqueNumber=UniqueNumber^nums[idx];
    }
    return UniqueNumber;
}