class Solution {
public:
    bool isValid(string s) {
        stack <char> d;
        char p;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                d.push(s[i]);
            }
            else {
                if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                    if(d.empty()) return false;
                    else {
                        p = d.top();
                        d.pop();
                        if(!((s[i] == ')' && p == '(') || (s[i] == '}' && p == '{') || (s[i] == ']' && p == '['))) {
                            return false;
                        }
                    }
                }
            }
        }
        if(!d.empty()) return false;
        return true;
    }
};