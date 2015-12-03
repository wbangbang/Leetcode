class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> v;
        for(int i = 0; i < nums.size(); i++) {
                map[nums[i]] = i + 1;  //in case of negative nums, all nums even the ones larger than target need to put in
        }   //because unordered_map does not contain duplicate keys, so the index stored in it was the largest one.
        for(int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            if(it != map.end()) {
                if(it->second == i + 1) continue;
                v.push_back(i + 1);
                v.push_back(it->second);
                return v;
            }
        }
        return v;
    }
};