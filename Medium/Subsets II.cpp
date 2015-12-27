class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        sort(nums.begin(), nums.end());
        backtracking(nums, temp, res, 0);
        return res;
    }
    
    void backtracking(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, int start) {
        int n = nums.size();
        for(int i = start; i < n; i++) {
            if(i > start && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            res.push_back(temp);
            backtracking(nums, temp, res, i + 1);
            temp.pop_back();
        }
    }
};