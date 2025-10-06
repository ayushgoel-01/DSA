class Solution {
#define P pair<int,pair<int,int>>
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n,false));
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = true;

        int maxi = grid[0][0];

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int lvl = top.first;
            int row = top.second.first;
            int col = top.second.second;

            maxi = max(maxi,lvl);
            if(row == n-1 && col == n-1) return maxi;

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    pq.push({grid[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return maxi;
    }
};