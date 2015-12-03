
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int count = 0, i = 0, j = 0;
        while(count < 16) {
            if(((n & (1 << (31 - i))) >> (31 - i)) == ((n & (1 << j)) >> j)) { //Notice: the operator's precedence.
                i++;                                                           //Notice: what are compared are ints.
                j++;
            }
            else if(((n & (1 << (31 - i))) >> (31 - i)) > ((n & (1 << j)) >> j)) {
                n = n & ~(1 << (31 - i));
                n = n | (1 << j);
                i++;
                j++;
            }
            else {
                n = n | (1 << (31 - i));
                n = n & ~(1 << j);
                i++;
                j++;
            }
            count++;
        }
        return n;
    }
};