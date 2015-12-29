class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp(3);//Give the size here to avoid push_back which will increase the runtime.
        int n = nums.size();
        if(n < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int sum, left = i + 1, right = n - 1;
            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if(!sum) {
                    temp[0] = nums[i];
                    temp[1] = nums[left];
                    temp[2] = nums[right];
                    res.push_back(temp);
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if(sum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }

        }
        return res;
    }
};