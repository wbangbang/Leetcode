class Solution {
public:
    int romanToInt(string s) {
        int num[128];
        num['I'] = 1; num['V'] = 5; num['X'] = 10; num['C'] = 100; num['L'] = 50; num['D'] = 500; num['M'] = 1000;
        int i = 0, result = 0;
        while(i < s.size() - 1) {
            if(num[s[i]] < num[s[i + 1]])
                result -= num[s[i]];
            else 
                result += num[s[i]];
            i++;
        }
        result += num[s[i]];
        return result;
    }
};