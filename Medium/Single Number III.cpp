class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> s;
        vector<int> r;
        for(int i = 0; i < nums.size(); i++) {
            if(s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
            }
            else {
                s.erase(nums[i]);
            }
        }
        for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
            r.push_back(*it);
        }
        return r;
    }
};