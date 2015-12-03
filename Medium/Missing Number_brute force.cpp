class Solution {
public:
    int missingNumber(vector<int>& nums) {
        priority_queue<int> p;
        for(int i = 0; i < nums.size(); i++) {
            p.push(nums[i]);
        }
        for(int i = p.size(); i > 0; i--) {
            if(i != p.top()) return i;
            p.pop();
        }
        return 0;
    }
};