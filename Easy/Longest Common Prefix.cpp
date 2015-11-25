class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        char temp;
        if(strs.size() == 0) return s;
        int j = 0;
        while(1) {
            int i = 0;
            if(strs[i].size() == 0 || j >= strs[i].size()) return s;
            temp = strs[i][j];
            while(i < strs.size()){
                if(strs[i].size() == 0 || j >= strs[i].size()) return s;
                if(strs[i][j] != temp) return s;
                i++;
            }
            s += temp;
            j++;
        }
    }
};