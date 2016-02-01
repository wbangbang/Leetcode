class ValidWordAbbr {
private:    
    unordered_map<string, set<string>> myMap;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto i: dictionary) {
          int n = i.size();
          string abbr = (n <= 2)? i: i[0] + to_string(n - 2) + i[n - 1];
          myMap[abbr].insert(i);
        }
    }

    bool isUnique(string word) {
        int n = word.size();
        string abbr = (n <= 2)? word: word[0] + to_string(n - 2) + word[n - 1];
        if(!myMap.count(abbr) || (myMap[abbr].size() == 1 && myMap[abbr].count(word))) return true;
        return false;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");