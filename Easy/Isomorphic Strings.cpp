class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(check(s, t) && check(t, s)) return true;
        else return false;
    }
    
    bool check(string s, string t) {
        array<int, 256> a;
        a.fill(0);
        for(int i = 0; i < s.size(); i++) {
            if(a[s[i]] == 0) a[s[i]] = t[i];
            else {
                if(a[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};