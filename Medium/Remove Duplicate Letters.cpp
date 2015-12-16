class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<unsigned int> count(26, 0);
        vector<bool> deploy(26, false);
        string result = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        } 
        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']--;
            if(result.empty()) {
                result.push_back(s[i]);
                deploy[s[i] - 'a'] = true;
                continue;
            }
            if(deploy[s[i] - 'a']) continue;
            while(s[i] < result.back() && !result.empty() && count[result.back() - 'a']) {
                deploy[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(s[i]);
            deploy[s[i] - 'a'] = true;
        }
        return result;
    }
};