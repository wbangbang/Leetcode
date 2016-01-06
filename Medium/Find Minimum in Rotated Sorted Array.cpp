class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        int n = nums.size(), left = 1, right = n - 1, min = nums[0];
        if(n == 1) return nums[0];
        if(nums[0] < nums[n - 1]) return nums[0];
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] > min) {
                left = mid + 1;
            }
            else {
                min = nums[mid];
                right = mid - 1;
            }
        }
        return min;
    }
};