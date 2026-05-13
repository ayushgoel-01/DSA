class Solution {
private:
    int solve(vector<vector<int>>& mat, int col, int n, int m){
        int ans = 0, maxi = 0;
        for(int i=0; i<n; i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                ans = i;
            }
        }
        return ans;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int start = 0, end = m-1;
        while(start <= end){
            int mid = (start + end)/2;
            int idx = solve(mat,mid,n,m);

            int left = (mid-1 >= 0) ? mat[idx][mid-1] : -1;
            int right = (mid+1 < m) ? mat[idx][mid+1] : -1;

            if(mat[idx][mid] > left && mat[idx][mid] > right) return {idx,mid};
            else if(mat[idx][mid] < left) end = mid-1;
            else start = mid+1;
        }
        return {-1,-1};
    }
};