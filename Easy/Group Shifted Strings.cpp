class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        if(strings.empty()) return res;
        unordered_map<string, vector<string>> myMap;
        for(int i = 0; i < strings.size(); i++) {
            myMap[helper(strings[i])].push_back(strings[i]);
        }
        for(auto i: myMap) {
            sort(i.second.begin(), i.second.end());
            res.push_back(i.second);
        }
        return res;
    }
    
    string helper(string s) {
        int diff = s[0] - 'a';
        for (char &c: s)
            c = (c - diff + 26) % 26 + 'a';
        return s;
    }
};
