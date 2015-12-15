class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int n = s.size(), f = 0, r = 0;
        while(r < n) {
            while(r < n && !isspace(s[r])) r++;
            reverse(s.begin() + f, s.begin() + r);
            f = ++r;
        }
    }
};