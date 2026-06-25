//int comp(int *const a,int const b)
int comp(const void *a, const void *b)
{
    int ia=*(const int*)a;
    int ib=*(const int *)b;

    return ia-ib;

}
int majorityElement(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),comp);
    return nums[numsSize/2];
}