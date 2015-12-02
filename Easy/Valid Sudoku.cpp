class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<bool, 9> a;a.fill(false);
       
        for(int i = 0; i < 9; i++) {                //check rows.
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(a[board[i][j] - '1'] == true) return false;
                    a[board[i][j] - '1'] = true;
                }
            }
            a.fill(false);
        }

        for(int i = 0; i < 9; i++) {                //check columns.
            for(int j = 0; j < 9; j++) {
                if(board[j][i] != '.') {
                    if(a[board[j][i] - '1'] == true) return false;
                    a[board[j][i] - '1'] = true;
                }
            }
            a.fill(false);
        }

        for(int i = 0; i < 9; i += 3) {             //check subboxes.
            for(int j = 0; j < 9; j += 3) {
                if(!subBoxes(board, i, j)) return false;
            }
        }
        
        return true;
    }
    
    bool subBoxes(vector<vector<char>> board, int i, int j) {
        array<bool, 9> a;
        a.fill(false);
        for(int x = i; x < i + 3; x++) {
            for(int y = j; y < j + 3; y++) {
                if(board[x][y] != '.') {
                    if(a[board[x][y] - '1'] == true) return false;
                    a[board[x][y] - '1'] = true;
                }
            }
        }
        return true;
    }
};