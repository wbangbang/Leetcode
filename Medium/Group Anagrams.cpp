class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        int i = 0;
        for(auto m: strs) {
            sort(m.begin(), m.end());
            map[m].push_back(strs[i++]);
        }
        vector<vector<string>> result;
        for(auto n: map) {
            sort(n.second.begin(), n.second.end());
            result.push_back(n.second);
        }
        return result;
    }
};