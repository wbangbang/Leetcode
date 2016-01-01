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

class Solution {//bit manipulation
public:
    vector<int> singleNumber(vector<int>& nums) {
        int m = 0;
        for(int i = 0; i < nums.size(); i++) {//due to single number x1, x2, m != 0, so m must has one bit which is not 0.
            m ^= nums[i];
        }
        int flag = m & (~(m -1)), a = 0, b = 0;//find the lowest bit which is 1.
        for(int i = 0; i < nums.size(); i++) {
            if(flag & nums[i]) {
                a ^= nums[i];
            }
            else {
                b ^= nums[i];
            }
        }
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};