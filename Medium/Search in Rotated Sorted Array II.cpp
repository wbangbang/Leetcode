class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int n = nums.size(), left = 0, right = n - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] == target || nums[right] == target) return true;
            if(nums[mid] < nums[right]) {
                if(target > nums[mid] && target < nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else if(nums[mid] > nums[right]) {
                if(target > nums[right] && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                right--;
            }
        }
        return false;
    }
};