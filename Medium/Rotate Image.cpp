//need extra O(n*n) space
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        if(!size) return;
        vector<vector<int>> temp;
        for(int i = 0; i < size; i++) {
            vector<int> v;
            for(int j = 0; j < size; j++) {
                v.push_back(matrix[i][j]);
            }
            temp.push_back(v);
        }
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                matrix[i][j] = temp[size - 1 - j][i];
            }
        }
    }
};

//in-place
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        if(!size) return;
        int temp;
        for(int i = 0; i < size / 2; i++) {
            for(int j = i; j < size - 1 - i; j++) {
                temp = matrix[size - 1 - i][size - 1 - j];
                matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
                matrix[j][size - 1 - i] = matrix[i][j];
                matrix[i][j] = matrix[size - 1 -j][i];
                matrix[size - 1 - j][i] = temp;
            }
        }
    }
};