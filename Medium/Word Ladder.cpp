class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        while(!q.empty()) {
            string temp = q.front().first;
            int len = q.front().second;
            q.pop();
            if(temp == endWord) return len;
            vector<string> neighbor = findNeighbor(temp, wordList);
            for(int i = 0; i < neighbor.size(); i++) {
                q.push(make_pair(neighbor[i], len + 1));
            }
        }
        return 0;
    }
    
    vector<string> findNeighbor(string temp, unordered_set<string>& wordList) {
        vector<string> res;
        for(int i = 0; i < temp.size(); i++) {
            char c = temp[i];
            for(int j = 0; j < 26; j++) {
                if(c == 'a' + j) continue;
                temp[i] = 'a' + j;
                if(wordList.count(temp)) {
                    res.push_back(temp);
                    wordList.erase(temp);
                }
            }
            temp[i] = c;
        }
        return res;
    }
};