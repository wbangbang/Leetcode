class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        if(words.empty()) return 0;
        int n = words.size();
        int index1[n] = {0}, index2[n] = {0}, i = 0, j = 0;
        for(int a = 0; a < n; a++) {
            if(words[a] == word1) {
                index1[i] = a;
                i++;
            }
            if(words[a] == word2) {
                index2[j] = a;
                j++;
            }
        }
        int min = n, a = 0, b = 0, temp;
        while(a < i) {
            while(b < j) {
                if(abs(index1[a] - index2[b]) < min) min = abs(index1[a] - index2[b]);
                b++;
            }
            a++;
            b = 0;
        }
        return min;
    }
};