class Solution {
public:
    bool search(vector<vector<char>>& board, vector<vector<int>>& vis, string word, int i, int j,
               int n, int m, int count) {
        if(count == word.size()) {
            return true;
        }
        for(int a = -1; a < 2; a += 2) {
            if(i+a >= 0 && i+a < n && word[count] == board[i+a][j] && vis[i+a][j] != 1) {
                vis[i][j] = 1;
                if(search(board, vis, word, i+a, j, n, m, count + 1)) {
                    return true;
                }
                vis[i][j] = 0;
            }
            if(j+a >= 0 && j+a < m && word[count] == board[i][j+a] && vis[i][j+a] != 1) {
                vis[i][j] = 1;
                if(search(board, vis, word, i, j+a, n, m, count + 1)) {
                    return true;
                }
                vis[i][j] = 0;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(word[0] == board[i][j] && vis[i][j] != 1) {
                    if(search(board, vis, word, i, j, n, m, 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};