class Solution {
private:
    bool solve(vector<vector<int>>& grid, int row, int col, int sum){
        for(int i=row; i<row+3; i++){
            int val = 0;
            for(int j=col; j<col+3; j++){
                if(grid[i][j] == 0 || grid[i][j] > 9) return false;
                val += grid[i][j];
            }
            if(val != sum) return false;
        }

        for(int j=col; j<col+3; j++){
            int val = 0;
            for(int i=row; i<row+3; i++){
                if(grid[i][j] == 0 || grid[i][j] > 9) return false;
                val += grid[i][j];
            }
            if(val != sum) return false;
        }

        int d1 = 0, d2 = 0;
        unordered_set<int> st;

        for(int i=row; i<row+3; i++){
            for(int j=col; j<col+3; j++){
                if(grid[i][j] == 0 || grid[i][j] > 9) return false;
                
                if(i-row == j-col) d1 += grid[i][j];
                if((i-row) + (j-col) == 2) d2 += grid[i][j];
                st.insert(grid[i][j]);
            }
        }
        return sum == d1 && sum == d2 && st.size() == 9;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int row=0; row<n-2; row++){
            for(int col=0; col<m-2; col++){
                if(solve(grid,row,col,15)) ans++;
            }
        }
        return ans;
    }
};