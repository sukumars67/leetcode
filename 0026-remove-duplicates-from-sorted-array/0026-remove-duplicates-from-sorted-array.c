int removeDuplicates(int* nums, int n) {
    int k=0;
    for(int i=0;i<n-1;i++)
    {
        if(nums[i]!=nums[i+1])
        {
            k++;
            nums[k]=nums[i+1];
        }
    }
    return k+1;
    
}