class NumMatrix {
private:
    vector<vector<int>> myV;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> temp = {0};
            for(int j = 0; j < matrix[0].size(); j++) {
                temp.push_back(temp.back() + matrix[i][j]);
            }
            myV.push_back(temp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            sum += myV[i][col2 + 1] - myV[i][col1];
        }
        return sum;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);