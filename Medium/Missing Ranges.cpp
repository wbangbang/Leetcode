class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long prev = (long)lower - 1;
        for(int i = 0; i <= nums.size(); i++) {
            long curr = (i == nums.size()) ? upper + 1 : nums[i];
            if(curr - prev > 1) res.push_back(helper(prev + 1, curr - 1));
            prev = curr;
        }
        return res;
    }
    
    string helper(int lower, int upper) {
        if(lower == upper) return to_string(lower);
        return to_string(lower) + "->" + to_string(upper);
    }
};