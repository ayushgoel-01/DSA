class Solution {
private:
    int n, m;
    int delrow[4] = {1,1,-1,-1};
    int delcol[4] = {1,-1,-1,1};
    int solve(int i, int j, int d, vector<vector<int>>& grid, int target, bool turn){
        int nrow = i + delrow[d];
        int ncol = j + delcol[d];

        if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || grid[nrow][ncol] != target) return 0;

        int ans = 1 + solve(nrow,ncol,d,grid,(target==2)?0:2,turn);
        if(turn){
            ans = max(ans,1 + solve(nrow,ncol,(d+1)%4,grid,(target==2)?0:2,false));
        }

        return ans;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    for(int d=0; d<4; d++){
                        ans = max(ans,1 + solve(i,j,d,grid,2,true));
                    }
                }
            }
        }
        return ans;
    }
};