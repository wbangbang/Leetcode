class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        backtracking(n, k, 1, res, temp);
        return res;
    }
    
    void backtracking(int n, int k, int start, vector<vector<int>>& res, vector<int>& temp) {
        if(k == 0) {
            res.push_back(temp);
            return;
        }
        
        for(int i = start; i <= n - k + 1; i++) {//to get all the the combinations instead of permutations, i's upperbound is n - k + 1. 
            temp.push_back(i);
            backtracking(n, k - 1, i + 1, res, temp);
            temp.pop_back();
        }
    }
};
