class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtracking(0, res, nums);
        return res;
    }
    
    void backtracking(int start, vector<vector<int>>& res, vector<int>& temp) {
        int n = temp.size();
        if(start == n - 1) {
            res.push_back(temp);
        }
        for(int i = start; i < n; i++) {
            swap(temp[start], temp[i]);
            backtracking(start + 1, res, temp);
            swap(temp[start], temp[i]);
        }
    }
};