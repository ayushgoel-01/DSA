class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));

        pq.push({0,0,0});
        dist[0][0] = 0;

        // up right down left
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int cost = top[0];
            int i = top[1];
            int j = top[2];

            for(int x=0; x<4; x++){
                int nrow = i + delrow[x];
                int ncol = j + delcol[x];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int ncost = cost;
                    if((grid[i][j] == 1 && x != 1) || (grid[i][j] == 2 && x != 3)|| 
                    (grid[i][j] == 3 && x != 2) || (grid[i][j] == 4 && x != 0)) ncost += 1;

                    if(dist[nrow][ncol] > ncost){
                        dist[nrow][ncol] = ncost;
                        pq.push({ncost,nrow,ncol});
                    }

                }
            }
        }
        return dist[n-1][m-1];
    }
};




// class Solution {            // Backtracking (TLE)
// int n, m;
// private:
//     int solve(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int cost){
//         if(i == n-1 && j == m-1) return cost;

//         // up right down left
//         int delrow[4] = {-1,0,1,0};
//         int delcol[4] = {0,1,0,-1};

//         vis[i][j] = true; 
//         int ans = 1e9;

//         for(int x=0; x<4; x++){
//             int nrow = i + delrow[x];
//             int ncol = j + delcol[x];

//             if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
//                 int newCost = cost;
//                 if((grid[i][j] == 1 && x != 1) || (grid[i][j] == 2 && x != 3)|| 
//                 (grid[i][j] == 3 && x != 2) || (grid[i][j] == 4 && x != 0)) newCost += 1;

//                 ans = min(ans,solve(nrow,ncol,grid,vis,newCost));
//             }
//         }
//         vis[i][j] = false; 
//         return ans;
//     }
// public:
//     int minCost(vector<vector<int>>& grid) {
//         this -> n = grid.size();
//         this -> m = grid[0].size();

//         vector<vector<bool>> vis(n, vector<bool>(m,false));
//         return solve(0,0,grid,vis,0);
//     }
// };