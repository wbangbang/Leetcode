class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.empty() && needle.empty()) return 0;
        if(haystack.empty()) return -1;
        if(needle.empty()) return 0;
        int m = haystack.size(), n = needle.size(), i = 0, j = 0, start = 0;
        while(i < m && j < n) {
            while(haystack[i] != needle[0] && i < m) i++;
            if(i == m) return -1;
            start = i;
            while(haystack[i] == needle[j] && i < m && j < n) {
                i++;
                j++;
            }
            if(j == n) return start;
            if(i == m) return -1;
            j = 0;
            i = start + 1;
        }
        return -1;
    }
};