class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int size = pow(2, nums.size());
        for(int i = 0; i < size; i++) {
            vector<int> v;
            int temp = i;
            unsigned int bit = 1;
            for(int j = 0; j < 32; j++) {
                if(temp & bit) v.push_back(nums[j]);
                bit = bit << 1;
            }
            sort(v.begin(),v.end());
            result.push_back(v);
        }
        return result;
    }
};