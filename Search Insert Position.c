int searchInsert(int* nums, int numsSize, int target) {
    int index;
    if(numsSize == 1) {
        if((*nums) >= target) return 0;
        else return 1;
    }
    if(numsSize % 2 == 0) {
        if(target == (*(nums + numsSize / 2))) return numsSize / 2;
        else if(target > (*(nums + numsSize / 2))) {
            if(numsSize / 2 + 1 <= numsSize - 1)
                index = numsSize / 2 + 1 + searchInsert(nums + numsSize / 2 + 1, numsSize / 2 - 1, target);
            else
                index = numsSize;
        }
        else {
            index = searchInsert(nums, numsSize / 2, target);
        }
    }
    else {
        if(target == (*(nums + (numsSize - 1) / 2))) return (numsSize - 1) / 2;
        else if(target > (*(nums + (numsSize - 1) / 2))) {
            if((numsSize - 1) / 2 <= numsSize - 1)                        //Without it, case [1,3],4 will appear Runtime error
                index = (numsSize - 1) / 2 + 1 + searchInsert(nums + (numsSize - 1) / 2 + 1, (numsSize - 1) / 2, target);
            else
                index = numsSize;
        }
        else {
            index = searchInsert(nums, (numsSize - 1) / 2, target);
        }
    }
    return index;
}