class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty()) return true;
        if(wordDict.empty()) return false;
        unordered_set<int> len;
        for(string str: wordDict) {
            len.insert((int)str.length());
        }
        int n = s.length();
        vector<bool> check(n + 1);
        check[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j: len) {
                if(j <= i) {
                   if(check[i - j] && wordDict.count(s.substr(i - j, j))) {
                        check[i] = true;
                        break;
                    } 
                }
            }
        }
        return check[n];
    }
};