class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, temp;
        vector<int> result;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] == target) {
                temp = mid;
                while(nums[temp - 1] == target && temp > 0) {
                    temp--;
                }
                result.push_back(temp);
                temp = mid;
                while(nums[temp + 1] == target && temp < nums.size() - 1) {
                    temp++;
                }
                result.push_back(temp);
                return result;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};