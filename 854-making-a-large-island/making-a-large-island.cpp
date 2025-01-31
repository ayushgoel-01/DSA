class Solution {
int delrow[4] = {-1,0,1,0};
int delcol[4] = {0,1,0,-1};
private:
    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int n, int id){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;

        int ans = 0;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            grid[row][col] = id;            // Assigning Unique ID in grid cell
            ans++;

            for(int x=0; x<4; x++){
                int nrow = row + delrow[x];
                int ncol = col + delcol[x];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol] &&
                grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return ans;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> vis(n, vector<bool>(n,false));
        unordered_map<int,int> idToArea;    // ID -> Area mapping

        int uniqueId = 10;
        for(int i=0; i<n; i++){             // Assign Unique ID to every group
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    idToArea[uniqueId] = bfs(i,j,grid,vis,n,uniqueId);
                    uniqueId++;
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) continue;

                unordered_set<int> st;
                int area = 1;           // Changing 0 to 1

                for(int x=0; x<4; x++){
                    int row = i + delrow[x];
                    int col = j + delcol[x];

                    if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] != 0 &&
                        st.count(grid[row][col]) <= 0){

                        int currArea = idToArea[grid[row][col]];
                        area += currArea;
                        st.insert(grid[row][col]);
                    }
                }
                if(area > n*n) area--;          // All cells are 1 so substract 1
                ans = max(ans,area);
            }
        }
        return ans;
    }
};