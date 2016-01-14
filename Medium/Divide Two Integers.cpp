class Solution {
public:
    int divide(int dividend, int divisor) {//corner case: quotient == abs(INT_MIN) and whether the quotient is positive or not.
        if(!divisor) return INT_MAX;
        if(!dividend) return 0;
        unsigned int db = abs(dividend), dc = abs(divisor);
        unsigned int quo = 0; 
        while(db >= dc) {
            int i;
            long mul = dc; //size of mul needs to be larger than 2147483648 * 2. 
            for(i = 0; mul <= db; i++) {
                mul = mul << 1;
            }
            quo += 1 << (i - 1);
            db -= mul >> 1;
        }
        return (dividend > 0) ^ (divisor > 0)? -quo: (quo > INT_MAX? INT_MAX: quo);
    }
};