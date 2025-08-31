class Solution {
private:
    bool isSafe(int row, int col, char ch, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[row][i] == ch || board[i][col] == ch) return false;
        }

        int i = 3*(row/3), j = 3*(col/3);       // For 3X3 board
        for(int k=0; k<3; k++){
            for(int l=0; l<3; l++){
                if(board[i+k][j+l] == ch) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.') continue;

                for(char ch='1'; ch<='9'; ch++){
                    if(isSafe(i,j,ch,board)){
                        board[i][j] = ch;

                        bool nextAns = solve(board);
                        if(nextAns) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};