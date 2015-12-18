class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) return 0;
        int left = 1, right = x;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(mid == x / mid) return mid;//the condition cannot be "mid * mid == x"
            else if(mid > x / mid) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return right;//int sqrt(x) is always not larger than the sqrt(x).
    }
};