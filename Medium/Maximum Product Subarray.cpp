class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size(), maxDP[n], minDP[n], res = nums[0];
        maxDP[0] = nums[0];
        minDP[0] = nums[0];
        for(int i = 1; i < n; i++) {
            maxDP[i] = nums[i];
            minDP[i] = nums[i];
            if(nums[i] > 0) {
                maxDP[i] = max(maxDP[i], nums[i] * maxDP[i - 1]);
                minDP[i] = min(minDP[i], nums[i] * minDP[i - 1]);
            }
            else if(nums[i] < 0) {
                maxDP[i] = max(maxDP[i], nums[i] * minDP[i - 1]);
                minDP[i] = min(minDP[i], nums[i] * maxDP[i - 1]);
            }
            res = max(res, maxDP[i]);
        }
        return res;
    }
};