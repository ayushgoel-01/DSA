class Solution {
private:
    bool bfs(int i, int j, vector<vector<int>>& grid, int n, int m){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 1;     // Mark as visited

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == n-1) return true;

            for(int x=0; x<4; x++){
                int nrow = row + delrow[x];
                int ncol = col + delcol[x];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0){
                    q.push({nrow,ncol});
                    grid[nrow][ncol] = 1;
                }
            }

        }
        return false;
    }

    bool solve(vector<vector<int>>& cells, int mid, int row, int col){
        vector<vector<int>> grid(row, vector<int>(col,0));

        for(int i=0; i<=mid; i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        for(int j=0; j<col; j++){
            if(grid[0][j] == 0 && bfs(0,j,grid,row,col)) return true;
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();

        int ans = 0;
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(solve(cells,mid,row,col)){
                ans = mid+1;
                start = mid+1;
            }
            else end = mid-1;
        }
        return ans;
    }
};