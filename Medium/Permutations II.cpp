class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used;
        used.assign(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, res, temp, used);
        return res;
    }
    
    void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, vector<bool>& used) {
        int n = nums.size();
        if(temp.size() == n) {
            res.push_back(temp);
        }
        for(int i = 0; i < n; i++) {
            if(used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            backtracking(nums, res, temp, used);
            temp.pop_back();
            used[i] = false;
        }
    }
};