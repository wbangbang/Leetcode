class Solution {
public:
    int uniquePaths(int m, int n) {
        array<array<int, 100>, 100> a;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!i && !j) a[i][j] = 0;
                if(!i || !j) a[i][j] = 1;
                else a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
        return a[m - 1][n - 1];
    }
};