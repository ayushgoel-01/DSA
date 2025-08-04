class Solution {
private:
    bool isValid(vector<string>& board, int row, int col, int n){
        // Check Upward
        for(int i=row-1; i>=0; i--){
            if(board[i][col] == 'Q') return false;
        }

        // Check Upper Left Diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        // Check Upper Right Diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve(vector<string>& board, int n, vector<vector<string>>& ans, int row){
        if(row >= n){
            ans.push_back(board);
            return;
        }

        for(int col=0; col<n; col++){
            if(isValid(board,row,col,n)){
                board[row][col] = 'Q';
                solve(board,n,ans,row+1);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        solve(board,n,ans,0);

        return ans;
    }
};