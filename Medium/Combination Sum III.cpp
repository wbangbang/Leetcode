class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        backtracking(k, n, 1, temp, res);
        return res;
    }
    
    void backtracking(int k, int n, int start, vector<int>& temp, vector<vector<int>>& res) {
        if(!k && !n) {
            res.push_back(temp);
            return;
        }
        for(int i = start; i < 10; i++) {
            if(i <= n) {
                temp.push_back(i);
                backtracking(k - 1, n - i, i + 1, temp, res);
                temp.pop_back();
            }
        }
    }
};