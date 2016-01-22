class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {//Attention: char.
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxS = 0;
        int dp[m][n] = {0};
        for(int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxS = max(dp[i][0], maxS);
            for(int j = 1; j < n; j++) {
                if(!i) {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else {
                    if(matrix[i][j] == '0') {
                        dp[i][j] = 0;
                    }
                    else {
                        dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])); 
                    }
                }
                maxS = max(dp[i][j], maxS);
            }
        }
        return maxS * maxS;
    }
};