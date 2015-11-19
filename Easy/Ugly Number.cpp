class Solution {
public:
    bool isUgly(int num) {
        int temp = num;
        if(num == 0) return false;
        if(num == 1) return true;
        while(temp % 2 == 0) {
            temp /= 2;
            if(temp == 1) return true;
        }
        while(temp % 3 == 0) {
            temp /= 3;
            if(temp == 1) return true;
        }
        while(temp % 5 == 0) {
            temp /= 5;
            if(temp == 1) return true;
        }
        return false;
    }
};