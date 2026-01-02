class Solution {
#define P pair<int,pair<int,int>>
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;

        queue<P> q;
        vector<vector<bool>> vis(n, vector<bool>(n,false));
        q.push({1,{0,0}});

        while(!q.empty()){
            int val = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(row == n-1 && col == n-1) return val;

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i == 0 && j == 0) continue;

                    int nrow = row + i;
                    int ncol = col + j;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && 
                    !vis[nrow][ncol]){
                        q.push({val+1,{nrow,ncol}});
                        vis[nrow][ncol] = true;
                    }
                }
            }
        }
        return -1;
    }
};