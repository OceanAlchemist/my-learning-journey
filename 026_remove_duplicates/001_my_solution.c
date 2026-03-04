int removeDuplicates(int* nums, int numsSize) {
    int n=numsSize,i=0,a=0,b[n];
    b[0]=nums[0];
    for(int k=1;k<n;k++)
    if(nums[k]>nums[k-1])
    {b[++a]=nums[k];
    }
    for(i=0;i<a+1;i++){
    nums[i]=b[i];}
    return a+1;
}
