class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int m = matrix.size(), n = matrix[0].size();
        int i, j, is = 0, ie = m - 1, js = 0, je = n - 1;
        while(is <= ie && js <= je) {
            for(j = js; j <= je; j++) {
                result.push_back(matrix[is][j]);
            }
            is++;
            if(is > ie) break;
            for(i = is; i <= ie; i++) {
                result.push_back(matrix[i][je]);
            }
            je--;
            if(je < js) break;
            for(j = je; j >= js; j--) {
                result.push_back(matrix[ie][j]);
            }
            ie--;
            if(ie < is) break;
            for(i = ie; i >= is; i--) {
                result.push_back(matrix[i][js]);
            }
            js++;
            if(js > je) break;
        }
        return result;
    }
};