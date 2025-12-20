class Solution {
#define P pair<int,pair<int,int>>
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        vector<vector<int>> ans(n, vector<int>(m,INT_MAX));
        queue<P> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = true;
                    ans[i][j] = 0;
                    q.push({0,{i,j}});
                }
            }
        }

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            ans[row][col] = min(ans[row][col],dist);

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    q.push({dist+1,{nrow,ncol}});
                }
            }
        }
        return ans;
    }
};