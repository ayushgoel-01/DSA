class Solution {
private:
    int area(int startRow, int endRow, int startCol, int endCol, vector<vector<int>>& grid) {
        int r1 = endRow, r2 = startRow, c1 = endCol, c2 = startCol;

        for(int i=startRow; i<endRow; i++){
            for(int j=startCol; j<endCol; j++){
                if(grid[i][j] == 1){
                    r1 = min(r1,i); c1 = min(c1,j);
                    r2 = max(r2,i); c2 = max(c2,j);
                }
            }
        }
        return (abs(r1-r2) + 1) * 1LL * (abs(c1-c2) + 1);
    }

    void solve(vector<vector<int>>& grid, int n, int m, int& ans){
        for(int rowSplit=1; rowSplit<n; rowSplit++){
            for(int colSplit=1; colSplit<m; colSplit++){
                // Case 1 & 4
                int top = area(0,rowSplit,0,m,grid);
                int bottomLeft = area(rowSplit,n,0,colSplit,grid);
                int bottomRight = area(rowSplit,n,colSplit,m,grid);

                ans = min(ans,top+bottomLeft+bottomRight);

                // Case 2 & 5
                int topLeft = area(0,rowSplit,0,colSplit,grid);
                int topRight = area(0,rowSplit,colSplit,m,grid);
                int bottom = area(rowSplit,n,0,m,grid);

                ans = min(ans,topLeft+topRight+bottom); 
            }
        }

        // Case 3 & 6
        for(int rowSplit1=1; rowSplit1<n; rowSplit1++){
            for(int rowSplit2=rowSplit1+1; rowSplit2<n; rowSplit2++){
                int top = area(0,rowSplit1,0,m,grid);
                int middle = area(rowSplit1,rowSplit2,0,m,grid);
                int bottom = area(rowSplit2,n,0,m,grid);

                ans = min(ans,top+middle+bottom);
            }
        }
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = INT_MAX;

        // Handle Case 1,2,3
        solve(grid,n,m,ans);
        
        // Rotate Grid
        vector<vector<int>> rotatedGrid(m, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rotatedGrid[j][n-i-1] = grid[i][j];
            }
        }

        // Handle Case 4,5,6
        solve(rotatedGrid,m,n,ans);
        return ans;
    }
};

    /* All the Cases 

        -------------
        |    (1)    |
        |           |
        -------------
        | (2) | (3) |
        |     |     |
        -------------

        -------------
        |     | (2) |
        |     |     |
          (1) -------
        |     |     |
        |     | (3) |
        -------------
        
        -------------
        |     |     |
        | (2) |     |
        ------- (1) |
        |     |     |
        | (3) |     |
        -------------

        -------------
        | (2) | (3) |
        |     |     |
        ------------
        |           |
        |    (1)    |
        -------------

        -------------
        |    (1)    |
        -------------
        |    (2)    |
        -------------
        |    (3)    |
        -------------

        -------------
        |   |   |   |
        |   |   |   |
        |(1)|(2)|(3)|
        |   |   |   |
        |   |   |   |
        -------------
    */   