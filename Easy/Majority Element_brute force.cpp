class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m, n, count1 = 0, count2 = 0;
        vector<int> n1, n2;
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i < nums.size()/2; i++) {
            n1.push_back(nums[i]);
        }
        for(int i = nums.size()/2; i < nums.size(); i++) {
            n2.push_back(nums[i]);
        }
        m = majorityElement(n1);
        n = majorityElement(n2);
        if(m == n) return m;
        for(int i = 0; i < nums.size(); i++) {
            if(m == nums[i]) count1++;
            if(n == nums[i]) count2++;
            if(count1 > nums.size()/2) return m;
            if(count2 > nums.size()/2) return n;
        }
    }
};