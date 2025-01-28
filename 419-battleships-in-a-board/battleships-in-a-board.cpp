class Solution {
private:
    void solve(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();

            for(int x=0; x<4; x++){
                int nrow = row + delrow[x];
                int ncol = col + delcol[x];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 'X' &&
                !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    ans++;
                    solve(i,j,board,vis);
                }
            }
        }
        return ans;
    }
};