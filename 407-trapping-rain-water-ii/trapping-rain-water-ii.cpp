class Solution {
#define P pair<int,pair<int,int>>
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        int ans = 0;
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m,false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    pq.push({heightMap[i][j],{i,j}});
                    vis[i][j] = true;
                }
            }
        }

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!pq.empty()){
            auto top = pq.top(); 
            pq.pop();

            int currh = top.first;
            int row = top.second.first;
            int col = top.second.second;

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                    ans += max(currh - heightMap[nrow][ncol],0);
                    pq.push({max(currh,heightMap[nrow][ncol]),{nrow,ncol}});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return ans;
    }
};