class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> temp = board;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                if(i - 1 >= 0 && temp[i - 1][j]) count++;
                if(j - 1 >= 0 && temp[i][j - 1]) count++;
                if(j - 1 >= 0 && i - 1 >= 0 && temp[i - 1][j - 1]) count++;
                if(j + 1 < n && i + 1 < m && temp[i + 1][j + 1]) count++;
                if(j + 1 < n && temp[i][j + 1]) count++;
                if(i + 1 < m && temp[i + 1][j]) count++;
                if(j - 1 >= 0 && i + 1 < m && temp[i + 1][j - 1]) count++;
                if(i - 1 >= 0 && j + 1 < n && temp[i - 1][j + 1]) count++;
                if(count < 2) board[i][j] = 0;
                else if(count > 3) board[i][j] = 0;
                else if(!board[i][j] && count == 3) board[i][j] = 1; 
            }
        }
        return;
    }
};

//in-place
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        //状态0：死细胞转为死细胞
        //状态1：活细胞转为活细胞
        //状态2：活细胞转为死细胞
        //状态3：死细胞转为活细胞
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                if(i - 1 >= 0 && (board[i - 1][j] == 1 || board[i - 1][j] == 2)) count++;
                if(j - 1 >= 0 && (board[i][j - 1] == 1 || board[i][j - 1] == 2)) count++;
                if(j - 1 >= 0 && i - 1 >= 0 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 2)) count++;
                if(j + 1 < n && i + 1 < m && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 2)) count++;
                if(j + 1 < n && (board[i][j + 1] == 1 || board[i][j + 1] == 2)) count++;
                if(i + 1 < m && (board[i + 1][j] == 1 || board[i + 1][j] == 2)) count++;
                if(j - 1 >= 0 && i + 1 < m && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 2)) count++;
                if(i - 1 >= 0 && j + 1 < n && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 2)) count++;
                if(count == 3 && !board[i][j]) board[i][j] = 3;
                else if((count < 2 || count > 3) && board[i][j]) board[i][j] = 2;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] %= 2;
            }
        }
        return;
    }
};