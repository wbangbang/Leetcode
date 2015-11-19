class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int result = 0;
        if(n <= 0) return false;
        if(n == 1) return true;
        while(1) {
            while(n) {
                result += (n % 10) * (n % 10);
                n /= 10;
            }
            if(result == 1) return true;
            if(s.find(result) == s.end())
                s.insert(result);
            else
                return false;
            n = result;
            result = 0;
        }
    }
};