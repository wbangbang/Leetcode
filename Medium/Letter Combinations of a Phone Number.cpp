class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        string temp = "";
        string check[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(res, temp, check, digits, 0);
        return res;
    }
    
    void backtracking(vector<string>& res, string& temp, string check[], string digits, int start) {
        int n = digits.size();
        if(start == n) {
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < check[digits[start] - '0'].length(); i++) {
            temp += check[digits[start] - '0'][i];
            backtracking(res, temp, check, digits, start + 1);
            temp.pop_back();
        }
    }
};