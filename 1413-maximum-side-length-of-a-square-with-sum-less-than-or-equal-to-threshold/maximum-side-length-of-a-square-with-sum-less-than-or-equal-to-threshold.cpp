class Solution {
private:
    int sum(vector<vector<int>>& pref, int i, int j, int r2, int c2){
        int sum = pref[r2][c2];
        if(i > 0) sum -= pref[i-1][c2];
        if(j > 0) sum -= pref[r2][j-1];
        if(i > 0 && j > 0) sum += pref[i-1][j-1];

        return sum;
    }

    bool solve(vector<vector<int>>& pref, int side, int threshold, int n, int m){
        for(int i=0; i+side-1<n; i++){
            for(int j=0; j+side-1<m; j++){
                int r2 = i + side - 1;
                int c2 = j + side - 1;

                if(sum(pref,i,j,r2,c2) <= threshold) return true;
            }
        }
        return false;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pref[i][j] = mat[i][j] + (i > 0 ? pref[i-1][j] : 0) + (j > 0 ? pref[i][j-1] : 0)
                            - ((i > 0 && j > 0) ? pref[i-1][j-1] : 0);
            }
        }

        int start = 1, end = min(n,m), ans = 0;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(solve(pref,mid,threshold,n,m)){
                ans = mid;
                start = mid+1;
            }
            else end = mid-1;
        }
        return ans;
    }
};