class Solution {
private:
    int solve(int start, int end, vector<int>& arr){
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] < 0){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans == -1 ? end+1 : ans;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int i=0; i<n; i++){
            int val = solve(0,m-1,grid[i]);
            ans += m-val;
        }
        return ans;
    }
};