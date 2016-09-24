class Solution {
public:
    string reverseString(string s) {
        int n = s.length();
        if(n == 0 || n == 1) return s;
        for(int i = 0; i < n / 2; i++) {
            swap(s, i, n - i - 1);
        }
        return s;
    }
    
    void swap(string& s, int f, int r) {
        char temp;
        temp = s[f];
        s[f] = s[r];
        s[r] = temp;
    }
};