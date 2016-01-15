class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                sum.push_back(nums[0]);
            }
            else {
                if(sum.back() < 0) {
                    sum.push_back(nums[i]);
                }
                else {
                    sum.push_back(sum.back() + nums[i]);
                }    
            }
        }
        int max = sum[0];
        for(int j = 0; j < sum.size(); j++) {
            if(sum[j] > max) max = sum[j];
        }
        return max;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return INT_MIN;
        int n = nums.size(); 
        if(n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        int max = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i] = nums[i];
            if(dp[i - 1] >= 0) dp[i] += dp[i - 1];
            if(dp[i] > max) max = dp[i];
        }
        return max;
    }
};