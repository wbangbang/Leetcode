class Solution {
public:
    int trailingZeroes(int n) {//count the number of the factor 5 in n!
        if(n == 0) return 0;
        int count = 0;
        while(n > 0) {
            count += n / 5;
            n /= 5;             //25 has two 5, 125 has three 5,and so on...
        }
        return count;
    }
};