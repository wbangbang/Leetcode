class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        array<int, 100000> l;
        if(nums.size() == 0) return 0;
        l[0] = 1;
        int maxLength = 1;
        for(int i = 1; i < nums.size(); i++) {
            int max = 0;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(l[j] > max) max = l[j];
                }
            }
            l[i] = max + 1;
            if(l[i] > maxLength) maxLength = l[i];
        }
        return maxLength;
    }
};