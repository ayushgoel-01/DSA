class Solution {
private:
    void solve(int i, int j, vector<vector<bool>>& ocean, int row, int col, vector<vector<int>>& heights, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m || ocean[i][j] || (row >= 0 && col >= 0 && 
        heights[row][col] > heights[i][j])) return;

        ocean[i][j] = true;

        solve(i+1,j,ocean,i,j,heights,n,m);
        solve(i,j+1,ocean,i,j,heights,n,m);
        solve(i-1,j,ocean,i,j,heights,n,m);
        solve(i,j-1,ocean,i,j,heights,n,m);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> atlantic(n, vector<bool>(m,false)), pacific(n, vector<bool>(m,false));

        for(int i=0; i<n; i++){
            solve(i,0,pacific,-1,-1,heights,n,m);
            solve(i,m-1,atlantic,-1,-1,heights,n,m);
        }
        for(int j=0; j<m; j++){
            solve(0,j,pacific,-1,-1,heights,n,m);
            solve(n-1,j,atlantic,-1,-1,heights,n,m);
        }

        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};