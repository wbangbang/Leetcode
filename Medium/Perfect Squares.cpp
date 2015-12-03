class Solution {
public:
    int numSquares(int n) {
        int a[n + 1];
        int i, j;
        for(i = 0; i <= n; i++) {
            a[i] = i;
            for(j = 1; j * j <= i; j++) {
                if(a[i - j * j] + 1 < a[i]) 
                    a[i] = a[i - j * j] + 1;
            }
        }
        return a[n];
    }
};