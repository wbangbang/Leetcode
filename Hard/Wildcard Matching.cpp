class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty()) {
            if(p == "*" || p.empty()) return true;
            return false;
        }
        if(p.empty()) return false;
        bool hasStar = false;
        int m = s.length(), n = p.length(), i = 0, j = 0, tempS, tempP;
        while(i < m) {
            //matching, continue
            if(p[j] == '?') {
                i++;
                j++;
            }
            //save current location when meeting '*', and scan s from tempS 
            else if(p[j] == '*') {
                hasStar = true;
                tempS = i;
                tempP = j;
                while(p[tempP] == '*' && tempP < n) tempP++;
                if(tempP == n) return true;
                j = tempP;
            }
            else {
                if(s[i] != p[j]) {
                    if(!hasStar) return false;
                    tempS++;
                    i = tempS;
                    j = tempP;
                }
                else {
                    i++;
                    j++;
                }
            }
        }
        while(p[j] == '*' && j < n) j++;
        if(j == n) return true;
        return false;
    }
};