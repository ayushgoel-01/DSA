class Solution {
private:
    bool solve(vector<vector<int>>& grid, int row, int col, int side, int n, int m){
        int val = 0;
        for(int j=0; j<side; j++){
            val += grid[row][col+j];
        } 

        int diagonal1 = 0, diagonal2 = 0;
        for(int i=0; i<side; i++){
            int sum = 0;
            for(int j=0; j<side; j++){
                sum += grid[row+i][col+j];

                if(i == j) diagonal1 += grid[row+i][col+j];
                if(i+j == side-1) diagonal2 += grid[row+i][col+j];
            }
            if(sum != val) return false;
        }

        if(diagonal1 != val || diagonal2 != val) return false;

        for(int j=0; j<side; j++){
            int sum = 0;
            for(int i=0; i<side; i++){
                sum += grid[row+i][col+j];
            }
            if(sum != val) return false;
        }
        return true;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int side=min(n,m); side>1; side--){
            for(int row=0; row<n; row++){
                for(int col=0; col<m; col++){
                    if(row+side <= n && col+side <= m && solve(grid,row,col,side,n,m)) return side;
                }
            }
        }
        return 1;
    }
};