class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, res, temp);
        return res;
    }
    
    void backtracking(vector<int>& c, int target, int start, vector<vector<int>>& res, vector<int>& temp) {
        int n = c.size(); //size of candidates.
        if(n == 0) return;
        if(!target) {//get one solution set.
            res.push_back(temp);
            return;
        }
        for(int i = start; i < n; i++) {
            if(i > 0 && c[i] == c[i - 1]) continue;
            if(c[i] <= target) {
                temp.push_back(c[i]);
                backtracking(c, target - c[i], i, res, temp);
                temp.pop_back();
            }
        }
    }
};