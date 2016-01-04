class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        int n = nums.size(), res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return sum;
                else if(sum < target) left++;
                else right--;
                if(abs(sum - target) < abs(res - target)) res = sum;
            }
        }
        return res;
    }
};