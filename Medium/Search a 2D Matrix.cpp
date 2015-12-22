class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1;
        while(top <= bottom) {
            int mid = (top + bottom) >> 1;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] > target) {
                bottom = mid - 1;
            }
            else {
                top = mid + 1;
            }
        }
        int row;
        if(!top) row = 0;
        else row = top - 1;
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};