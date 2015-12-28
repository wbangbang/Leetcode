class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool isrow1Zero = false, iscol1Zero = false;
        for(int j = 0; j < n; j++) {
            if(!matrix[0][j]) {
                isrow1Zero = true;
                break;
            }
        }
        for(int i = 0; i < m; i++) {
            if(!matrix[i][0]) {
                iscol1Zero = true;
                break;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    if(!matrix[i][0]) matrix[i][j] = 0;
                    else if(!matrix[0][j]) matrix[i][j] = 0;
                }
        }
        if(isrow1Zero) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if(iscol1Zero) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};