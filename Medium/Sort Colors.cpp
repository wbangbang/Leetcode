class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(),c0 = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) c0++;
            else if(nums[i] == 1) c1++;
            else c2++;
        }
        for(int i = 0; i < n; i++) {
            if(c0) {
                nums[i] = 0;
                c0--;
                continue;
            }
            if(c1) {
                nums[i] = 1;
                c1--;
                continue;
            }
            if(c2) {
                nums[i] = 2;
                c2--;
            }
        }
    }
};