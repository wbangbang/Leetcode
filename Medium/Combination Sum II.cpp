class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        if(candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, temp, res);
        return res;
    }
    
    void backtracking(vector<int>& c, int target, int start, vector<int>& temp, vector<vector<int>>& res) {
        int n = c.size();
        if(!target) {
            res.push_back(temp);
            return;
        }
        for(int i = start; i < n; i++) {
            if(i > start && c[i] == c[i - 1]) continue;
            if(c[i] <= target) {
                temp.push_back(c[i]);
                backtracking(c, target - c[i], i + 1, temp, res);
                temp.pop_back();
            }
        }
    }
};