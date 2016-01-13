class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word == "") return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, visited, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index, int i, int j) {
        if(index == word.length()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index] || visited[i][j]) return false;
        visited[i][j] = true;
        if(dfs(board, visited, word, index + 1, i + 1, j)) return true;
        if(dfs(board, visited, word, index + 1, i - 1, j)) return true;
        if(dfs(board, visited, word, index + 1, i, j + 1)) return true;
        if(dfs(board, visited, word, index + 1, i, j - 1)) return true;
        visited[i][j] = false;
        return false;
    }
};