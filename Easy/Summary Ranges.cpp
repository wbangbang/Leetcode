class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if(nums.size() == 0) return v;
        int i = 0;
        while(i < nums.size()) {
            string s = "";
            int flag = 0;
            s += to_string(nums[i++]);
            while(nums[i] - nums[i - 1] == 1 && i < nums.size()) {
                i++;
                flag++;
            }
            if(flag)
                s += "->" + to_string(nums[i - 1]);
            v.push_back(s);
        }
        return v;
    }
};