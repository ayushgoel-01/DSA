class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && (i == 0 || i == n-1 || j == 0 || j == m-1)){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] &&
                 board[nrow][ncol] == 'O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};