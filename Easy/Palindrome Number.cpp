class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0) return false;
        int n = x;
        int rn = 0;
        while(n != 0) {
            rn = rn * 10 + n % 10;
            n /= 10;
        }
        if(rn == x) return true;
        else return false;
        
    }
};