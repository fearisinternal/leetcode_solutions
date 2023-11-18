class Solution {
public:
    vector<vector<string>>ans;

    bool isValid(vector<string>&board, int row, int col) {
        //check col
        for (auto i = 0; i<row; i++) {
            if (board[i][col]=='Q') {
                return false;
            }
        }
        //check left-right
        for (auto i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if (board[i][j]=='Q') {
                return false;
            }
        }
        //check right-left
        for (auto i=row-1, j=col+1; i>=0 && j<board.size(); i--, j++) {
            if (board[i][j]=='Q') {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<string>&board, int row) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        for (auto i = 0; i < board.size(); i++) {
            if (isValid(board, row, i)) {
                board[row][i] = 'Q';
                dfs(board,row+1);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return {{}};
        vector<string> board(n,string(n,'.'));
        dfs(board, 0);
        return ans;
    }
};