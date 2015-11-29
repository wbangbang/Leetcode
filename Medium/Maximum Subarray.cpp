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