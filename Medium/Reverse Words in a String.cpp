class Solution {
public:
    void reverseWords(string &s) {
        int size = s.size();
        vector<string> v;
        int i = 0;
        while(i < size) {
            string temp;
            while(s[i] != ' ' && i < size) {
                temp += s[i];
                i++;
            }
            if(!temp.empty()) v.push_back(temp);
            i++;
        }
        s.clear();
        for(int j = v.size() - 1; j >= 0; j--) {
            s += v[j];
            if(j) s += ' ';
        }
    }
};