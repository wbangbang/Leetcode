
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int n = nums.size(), left = 0, right = n - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] == target) return mid;
            if(nums[right] == target) return right;
            if(nums[mid] < nums[right]) {
                if(target > nums[mid] && target < nums[right])  {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if(target < nums[mid] && target > nums[right]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};