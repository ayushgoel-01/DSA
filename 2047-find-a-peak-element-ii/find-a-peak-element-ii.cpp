class Solution {
private:
    int solve(vector<vector<int>>& mat, int j, int n){
        int maxi = INT_MIN, ans = 0;
        for(int i=0; i<n; i++){
            if(mat[i][j] > maxi){
                maxi = mat[i][j];
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
            int mid = (start + end) / 2;
            int idx = solve(mat,mid,n);

            int left = (mid-1) >= 0 ? mat[idx][mid-1] : -1;
            int right = (mid+1) < m ? mat[idx][mid+1] : -1;

            if(mat[idx][mid] > left && mat[idx][mid] > right){
                return {idx,mid};
            }
            else if(mat[idx][mid] < left) end = mid-1;
            else start = mid+1;
        }
        return {-1,-1};
    }
};