int comp(const void *a,const void *b)
{
    int ia=*(const int*)a;
    int ib=*(const int*)b;

    return ia-ib;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),comp);
    int count =0;
    for(int idx=0;idx<numsSize-1;idx++)
    {
        if(nums[idx]==nums[idx+1])
        {
            return true;
        }
    }
    return false;
}