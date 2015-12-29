class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int m = triangle.size();
        vector<int> temp(m);
        for(int i = m - 1; i >=0; i--) {
            int n = triangle[i].size();
            for(int j = 0; j < n; j++) {
                if(i == m - 1) {
                    temp[j] = triangle[i][j];
                }
                else {
                    temp[j] = triangle[i][j] + min(temp[j], temp[j + 1]);
                }
            }
        }
        return temp[0];
    }
};