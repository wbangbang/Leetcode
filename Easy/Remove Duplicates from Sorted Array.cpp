class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        while(j < nums.size()) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
                j++;
            }
            else {
                j++;
            }
        }
        return i + 1;
    }
};