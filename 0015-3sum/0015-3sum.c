/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int comp(const void *a,const void *b)
{
    int ia= *(const int*)a;
    int ib= *(const int*)b;
    return (ia>ib)-(ia<ib);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

  int Capcity=64;
  int **result=(int**)malloc(Capcity*sizeof(int*));
  *returnColumnSizes=(int*)malloc(Capcity*sizeof(int));
  *returnSize=0;
  qsort(nums,numsSize,sizeof(int),comp);
  for(int idx=0;idx<numsSize-2;idx++)
  {
    if(nums[idx]>0)
    {
        break;
    }
    if(idx>0 && nums[idx]==nums[idx-1]) continue;
    int target =-nums[idx];
    int l=idx+1;
    int r=numsSize-1;
    while(l<r)
    {
        int sum=nums[l]+nums[r];
        if(sum==target)
        {
            if(*returnSize>=Capcity)
            {
                Capcity*=2;
                result=(int**)realloc(result,Capcity*sizeof(int*));
                * returnColumnSizes = ( int * ) realloc ( * returnColumnSizes , Capcity * sizeof ( int ) ) ; // Fixed: Added missing realloc
            }
            int *triplet=(int*)malloc(3*sizeof(int));
            triplet[0]=nums[idx];
            triplet[1]=nums[l];
            triplet[2]=nums[r];
            result[*returnSize]=triplet;
            (*returnColumnSizes)[*returnSize]=3;
            (*returnSize)++;
            while(l<r && nums[l]==nums[l+1])l++;
            while(l<r && nums[r]==nums[r-1])r--;
            l++;
            r--;

        }
        else if(sum>target)
        {
            r--;
        }
        else
        {
            l++;
        }
    }

  }
  return result;


}