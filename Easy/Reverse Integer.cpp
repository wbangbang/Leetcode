class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        if(x <= -2147483648) return 0;
        if(x < 0) {
            x *= -1;
            flag = -1;
        }
        if(x / 10 < 1) return x * flag;
        int rx = 0;
        while(x != 0) {
            if(rx > 2147483647 / 10) return 0;
            rx = rx * 10 + x % 10;
            x /= 10;
        }
        return rx * flag;
    }
};