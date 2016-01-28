class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(!n) return res;
        string temp = "";
        backtracking(res, temp, n, 0, 0);
        return res;
    }
    
    void backtracking(vector<string>& res, string& temp, int n, int left, int right) {
        if(left == n && right == n) {
            res.push_back(temp);
            return ;
        }
        //if the number of '(' is smaller than n, we can add '('.
        if(left < n) {
            temp.push_back('(');
            backtracking(res, temp, n, left + 1, right);
            temp.pop_back();
        }
        //if the number of ')' is smaller than the number of '(', we can add ')'.
        if(right < left) {
            temp.push_back(')');
            backtracking(res, temp, n, left, right + 1);
            temp.pop_back();
        }
    }
};