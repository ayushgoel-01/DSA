class DSU{
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        parent.resize(n);
        size.resize(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 0;
        }
    }

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int xParent = find(x);
        int yParent = find(y);

        if(xParent == yParent) return;

        if(size[xParent] > size[yParent]){
            parent[yParent] = xParent;
            size[xParent] += size[yParent];
        }
        else{
            parent[xParent] = yParent;
            size[yParent] += size[xParent];
        }
    }

    void setValue(int i, int val){
        size[i] = val;
    }

    int findMax(){
        return *max_element(size.begin(),size.end());
    }
};

class Solution {            // Using DSU
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU dsu(n*m);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) continue;
                int idx = i * m + j;
                dsu.setValue(idx,grid[i][j]);
            }
        }

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) continue;

                for(int x=0; x<4; x++){
                    int nrow = i + delrow[x];
                    int ncol = j + delcol[x];
                    int idx = i * m + j;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] > 0){
                        int nidx = nrow * m + ncol;
                        dsu.Union(idx,nidx);
                    }
                }
            }
        }
        return dsu.findMax();
    }
};




// class Solution {            // Using BFS
// private:
//     int solve(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size();
//         int m = grid[0].size();

//         queue<pair<int,int>> q;
//         q.push({i,j});
//         vis[i][j] = true;

//         int delrow[4] = {-1,0,1,0};
//         int delcol[4] = {0,1,0,-1};
//         int ans = 0;

//         while(!q.empty()){
//             auto [row,col] = q.front();
//             q.pop();
//             ans += grid[row][col];

//             for(int x=0; x<4; x++){
//                 int nrow = row + delrow[x];
//                 int ncol = col + delcol[x];

//                 if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] > 0 &&
//                 !vis[nrow][ncol]){
//                     vis[nrow][ncol] = true;
//                     q.push({nrow,ncol});
//                 }
//             }
//         }
//         return ans;
//     }
// public:
//     int findMaxFish(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         vector<vector<bool>> vis(n, vector<bool>(m,false));
//         int maxi = 0;

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j] > 0 && !vis[i][j]) maxi = max(maxi,solve(i,j,grid,vis));
//             }
//         }
//         return maxi;
//     }
// };