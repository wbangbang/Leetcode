class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> myset;
        for(int i = 0; i < nums.size(); i++) {
            myset.insert(nums[i]);
        }
        int max = 1, count = 1, j = 0, last;
        for(auto i: myset) {
            if(j) {
                if(i - last != 1) {
                    count = 1;
                    if(count > max) max = count;
                } 
                else count++;
            }
            last = i;
            j++;
            if(count > max) max = count;
        }
        return max;
    }
};