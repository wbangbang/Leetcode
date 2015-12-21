class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int i = 0, index = nums[0], max = nums[0];
        while(i < n) {
            index = max; 
            if(index == i) return false;
            for(int j = i; j <= index; j++) {
                if(nums[j] + j > max) {
                    max = nums[j] + j;
                }
                if(max >= n - 1) return true;//if the max is larger than n - 1, we are done. 
            }
            i = index;
        }
    }
};