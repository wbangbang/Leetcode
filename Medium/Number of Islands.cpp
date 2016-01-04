class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != '0') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size()) return;
        if(j < 0 || j >= grid[0].size()) return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};