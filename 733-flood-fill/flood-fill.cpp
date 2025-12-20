class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.push({sr,sc});

        int val = image[sr][sc];

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = color;

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && 
                image[nrow][ncol] == val){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return image;
    }
};