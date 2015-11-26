/*
M(i): amount of money of ith house
V(i) = max{V(i - 2) + M(i), V(i - 1)}
V(0) = 0
V(1) = M(1)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> v;
        int s = nums.size();
        if(s == 0) return 0;
        if(s == 1) return nums[0];
        v.push_back(0);
        v.push_back(nums[0]);
        int j = 2;
        for(int i = 1; i < s; i++) {
            v.push_back(max(v[j - 1], v[j - 2] + nums[i]));
            j++;
        }
        return v.back();
    }
    
    int max(int a, int b) {
        if(a > b) return a;
        else return b;
    }
};