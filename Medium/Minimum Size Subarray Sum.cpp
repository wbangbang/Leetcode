class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size(), i = 0, j = 0, min = 2147483647, sum = 0;
        while(j < n) {
            while(j < n && sum < s) {
                sum += nums[j++];
            }
            if(sum >= s) {
                while(sum >= s && i < j) {
                    sum -= nums[i++];
                }
                min = findMin(min, j - i + 1);
            }
        }
        return min == 2147483647 ? 0 : min;
    }
    
    int findMin(int a, int b) {
        return a < b ? a : b;
    }
};