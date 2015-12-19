class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if((m ^ n) > m) return 0;//if the number of n's digits is larger than m's, return 0.
        if(m == n) return m;
        int result = m;
        for(unsigned int i = m + 1; i <= n; i++) {//i must be unsigned int, otherwise under the case: m=2147483646, n=2147483647, i will overflow.
            result &= i;
        }
        return result;
    }

};