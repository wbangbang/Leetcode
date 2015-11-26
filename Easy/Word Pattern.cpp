class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> temp, v;
        v.assign(26, "");
        int i = 0;
        while(i < str.size()) {
            string s = "";
            while(str[i] != ' ' && i < str.size()) {
                s += str[i];
                i++;
            }
            temp.push_back(s);
            i++;
        }
        if(pattern.size() != temp.size()) return false;
        for(int j = 0; j < pattern.size(); j++) {
            int val = pattern[j] - 'a';
            if(v[val] == "") {
                v[val] = temp[j];
            }
            else {
                if(v[val] != temp[j]) return false;
            }
        }
        vector<char> v1;
        v1.assign(256, '\0');
        for(int j = 0; j < temp.size(); j++) {
            int x = temp[j].size() - 1;
            int val = temp[j][0] + temp[j][x] - 'a';
            if(v1[val] == '\0') {
                v1[val] = pattern[j];
            }
            else {
                if(v1[val] != pattern[j]) return false;
            }
        }
        return true;
    }
};