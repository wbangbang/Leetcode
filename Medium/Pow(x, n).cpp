class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1;
        bitset<32> b(abs(n));
        double result = 1;
        for(int i = b.size() - 1; i >= 0; i--) {
            result *= result;
            if(b[i])
                result *= x;
        }
        if(n > 0) return result;
        else return 1 / result;
    }
};