class Solution {
private:
    void getReverse(vector<int>& v, int k){
        int n = v.size();

        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+n-k);
        reverse(v.begin()+n-k,v.end());
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m,0));

        int cycles = min(n,m)/2;

        int startRow = 0;
        int endRow = n-1;
        int startCol = 0;
        int endCol = m-1;

        int startRow1 = 0;
        int endRow1 = n-1;
        int startCol1 = 0;
        int endCol1 = m-1;

        while(cycles--){


            vector<int> v;
            for(int j=startCol; j<=endCol; j++){
                v.push_back(grid[startRow][j]);
            }
            startRow++;

            for(int i=startRow; i<=endRow; i++){
                v.push_back(grid[i][endCol]);
            }
            endCol--;

            for(int j=endCol; j>=startCol; j--){
                v.push_back(grid[endRow][j]);
            }
            endRow--;

            for(int i=endRow; i>=startRow; i--){
                v.push_back(grid[i][startCol]);
            }
            startCol++;

            int size = v.size();
            int newK = k % size;

            getReverse(v,newK);

            int idx = 0;

            for(int j=startCol1; j<=endCol1; j++){
                ans[startRow1][j] = v[idx++];
            }
            startRow1++;

            for(int i=startRow1; i<=endRow1; i++){
                ans[i][endCol1] = v[idx++];
            }
            endCol1--;

            for(int j=endCol1; j>=startCol1; j--){
                ans[endRow1][j] = v[idx++];
            }
            endRow1--;

            for(int i=endRow1; i>=startRow1; i--){
                ans[i][startCol1] = v[idx++];
            }
            startCol1++;
        }
        return ans;
    }
};