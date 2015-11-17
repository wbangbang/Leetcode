class Solution {
public:
    int titleToNumber(string s) {
        int i = s.size();
        int result = 0;
        while(i > 1) {
            result += (s[s.size() - i] - 64) * pow(26, --i);
        }
        result += (s.back() - 64);
        return result;
    }
};