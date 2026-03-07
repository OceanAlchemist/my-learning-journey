int removeElement(int* nums, int numsSize, int val) {
    int b=0;
    for(int i=0;i<numsSize;i++)
    if(nums[i]!=val)
    {nums[b]=nums[i];
    b++;
    }
    return b;
}
