int cmp(void const *a,void const *b)
{
    int ia=*(const int*)a;
    int ib=*(const int*)b;

    return (ia>ib)-(ia<ib);
}
int missingNumber(int* nums, int numsSize) {
    int n=numsSize;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int idx=0;idx<n;idx++)
    {
        if(nums[idx]!=idx)
        {
            return idx;
        }
    }
    return numsSize;
}