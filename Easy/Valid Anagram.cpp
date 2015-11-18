class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int num1[128] = {0}, num2[128] = {0};
        for(int i = 0; i < s.size(); i++) {
            num1[s[i]]++;
            num2[t[i]]++;
        }
        for(int i = 97; i < 123; i++) {
            if(num1[i] != num2[i]) return false;
        }
        return true;
    }
};