class Solution {
private:
    bool solve(int idx, int i, int j, vector<vector<char>>& board, string& word){
        int n = board.size();
        int m = board[0].size();
        
        if(idx >= word.size()) return true;
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        

        if(word[idx] != board[i][j]) return false;

        bool ans = false;
        if(board[i][j] == word[idx]){
            char ch = board[i][j];
            board[i][j] = '*';
            
            ans = solve(idx+1,i+1,j,board,word) || solve(idx+1,i-1,j,board,word) ||
                solve(idx+1,i,j+1,board,word) || solve(idx+1,i,j-1,board,word);

            board[i][j] = ch;
        }
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(solve(0,i,j,board,word)) return true;
            }
        }
        return false;
    }
};