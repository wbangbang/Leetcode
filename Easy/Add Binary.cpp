class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        if(a == "" && b == "") return res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.length(), b.length()), carry = 0;
        for(int i = 0; i < n; i++) {
            if(i < a.length()) carry += a[i] - '0';
            if(i < b.length()) carry += b[i] - '0';
            if(carry >= 2) {
                res += carry - 2 + '0';
                carry = 1;
            }
            else {
                res += carry + '0';
                carry = 0;
            }
        }
        if(carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};