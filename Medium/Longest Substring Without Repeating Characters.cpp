class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        vector<int> check;
        check.assign(256, -1);
        int start = 0, max = 0, len = 0;
        for(int i = 0; i < s.length(); i++) {
            if(check[s[i]] < start) {
                check[s[i]] = i;
                len++;
            }
            else {
                start = check[s[i]] + 1;
                len = i - start + 1;
                check[s[i]] = i;
            }
            if(len > max) max = len;
        }
        return max;
    }
};