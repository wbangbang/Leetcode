class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        int count = 0;
        int i = s.size() - 1;
        while(s[i] == ' ' && i > 0) {
            i--;
        }
        for(int j = i; s[j] != ' ' && j >= 0; j--) {
            count++;
        }
        return count;
    }
};