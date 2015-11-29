class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> sum = grid;
        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < m; i++)
            sum[i][0] += sum[i - 1][0];
        for(int i = 1; i < n; i++)
            sum[0][i] += sum[0][i - 1];
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                sum[i][j] += min(sum[i - 1][j], sum[i][j - 1]);
            }
        }
        return sum[m - 1][n - 1];
    }
    
    int min(int a, int b) {
        if(a > b) return b;
        else return a;
    }
};