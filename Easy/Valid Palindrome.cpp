class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int n = s.length();
        int i = 0, j = n - 1;
        while(i < j) {
            while(!isalnum(s[i]) && i < j) {
                i++;
            }
            while(!isalnum(s[j]) && i < j) {
                j--;
            }
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};